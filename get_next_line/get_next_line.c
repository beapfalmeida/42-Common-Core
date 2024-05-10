#include "get_next_line.h"

char	*readlines(int fd, char *stash)
{
	char	*buffer;
	int	bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while (bytes > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n') )
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			size;
	int			len_line;

	if (!stash)
		stash = NULL;
	stash = readlines(fd, stash);
	len_line = ft_strclen(stash, '\n');
	line = ft_strdup(stash, len_line + 1);
	if (!line)
		free(line);
	size = ft_strclen(stash + len_line + 1, '\0');
	if(!ft_strclen(stash, '\0'))
		return (NULL);
	stash = ft_strdup(stash + len_line + 1, size);
	if (!stash)
		free(stash);
	return (line);
}

int     main(void)
{
    int     fd;
    char    *line;
	int i = 2;
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("open error");
        return (1);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}