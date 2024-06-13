/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:33:28 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/13 17:51:41 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strclen(char *str, char c);
char	*ft_strdupp(char *src, int size);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchrr(const char *s, int c);
char	*readlines(int fd, char	*stash);
char	*free_dataa(char *stash, char *buffer);

#endif
