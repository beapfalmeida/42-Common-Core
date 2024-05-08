#include "get_next_line.h"

char	*readlines(int fd, char *stash)
{
	char	*buffer;
	int	i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
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
	size = ft_strclen(stash + len_line + 1, '\0') - len_line;
	free(stash);
	stash = ft_strdup(stash + len_line + 1, size);
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
    while (i--)
    {
        printf("%s", line);
        line = get_next_line(fd);
		free(line);
    }
    close(fd);
    return (0);
}