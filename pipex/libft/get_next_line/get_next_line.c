/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:33:00 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/13 17:34:34 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_dataa(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

char	*readlines(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	*buffer = 0;
	bytes = 1;
	while (bytes > 0 && !ft_strchrr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_dataa(stash, buffer));
		buffer[bytes] = '\0';
		stash = ft_strjoinn(stash, buffer);
	}
	if (*stash == '\0')
		return (free_dataa(stash, buffer));
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			size;
	int			len_line;
	char		*stashtemp;

	if (!stash)
		stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = readlines(fd, stash);
	if (!stash)
		return (NULL);
	len_line = ft_strclen(stash, '\n');
	line = ft_strdupp(stash, len_line + 1);
	if (!line)
		return (NULL);
	size = ft_strclen(stash, '\0') - len_line;
	stashtemp = stash;
	stash = ft_strdupp(stash + len_line + 1, size);
	free (stashtemp);
	if (!stash)
		free(stash);
	return (line);
}
