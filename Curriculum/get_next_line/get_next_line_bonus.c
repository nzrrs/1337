/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:23:38 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/12 09:23:47 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*get_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*new_node;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = ft_strdup("");
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static void	remove_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev == NULL)
				*head = current->next;
			else
				prev->next = current->next;
			free(current->stash);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static char	*fill_node_stash(int fd, char *read_buf, char *stash)
{
	ssize_t	bytes_read;
	char	*old;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(stash, read_buf);
		free(old);
	}
	if (!stash || !stash[0])
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*extract_trim(int fd, t_list **head, t_list *node)
{
	char	*nl;
	char	*old;
	char	*line;

	nl = ft_strchr(node->stash, '\n');
	if (nl)
	{
		line = ft_substr(node->stash, 0, (nl - node->stash) + 1);
		if (nl[1] != '\0')
		{
			old = node->stash;
			node->stash = ft_strdup(nl + 1);
			free(old);
		}
		else
			remove_node(head, fd);
	}
	else
	{
		line = ft_strdup(node->stash);
		remove_node(head, fd);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*read_buf;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&head, fd);
	if (!node)
		return (NULL);
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	node->stash = fill_node_stash(fd, read_buf, node->stash);
	free(read_buf);
	if (node->stash == NULL)
	{
		remove_node(&head, fd);
		return (NULL);
	}
	line = extract_trim(fd, &head, node);
	return (line);
}
