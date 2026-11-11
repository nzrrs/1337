/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:56:57 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/08 11:44:04 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// EXT LIBRARIES
# include <stdlib.h>
# include <unistd.h>

// FALLBACK MACRO DEF FOR BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// MACROS
# define SIZET_MAX 18446744073709551615UL
// MAIN PROTOTYPES
char	*get_next_line(int fd);

// UTILS PROTOTYPES
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
#endif
