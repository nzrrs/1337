/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:54:03 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/21 12:58:40 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	size_t	len;
	t_list	*p;

	len = 0;
	p = lst;
	while (p)
	{
		len++;
		p = p->next;
	}
	return (len);
}
