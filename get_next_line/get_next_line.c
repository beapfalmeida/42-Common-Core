/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:33:00 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/05/13 18:33:43 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_data(char *stash, char *buffer)
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
	bytes = BUFFER_SIZE;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_data(stash, buffer));
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	if (*stash == '\0')
		return (free_data(stash, buffer));
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
	line = ft_strdup(stash, len_line + 1);
	if (!line)
		return (NULL);
	size = ft_strclen(stash, '\0') - len_line;
	stashtemp = stash;
	stash = ft_strdup(stash + len_line + 1, size);
	free (stashtemp);
	if (!stash)
		free(stash);
	return (line);
}

// int     main(void)
// {
//     int     fd;
//     char    *line;
// 	int i = 2;
//     fd = open("example.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("open error");
//         return (1);
//     }
//     line = get_next_line(fd);
//     while (line != NULL)
//     {
//         printf("%s", line);
// 		free(line);
//         line = get_next_line(fd);
//     }
//     close(fd);
//     return (0);
// }