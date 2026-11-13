/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:23:58 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/12 09:24:10 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// EXT LIBRARIES
# include <stdlib.h>
# include <unistd.h>

// FALLBACK MACRO DEF FOR BUFFER_SIZE AND MAX_FD
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

// MAIN PROTOTYPES
char	*get_next_line(int fd);

// UTILS PROTOTYPES
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
#endif
