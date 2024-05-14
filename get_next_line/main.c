#include "get_next_line.h"

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
		free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
