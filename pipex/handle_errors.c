# include "pipex.h"

void handle_errors(int c, char *strerr)
{
	if (c == -1)
		perror(strerr);
}

void	badpath(char *path, char *cmd)
{
	if (!path)
	{
		ft_printf("Command %s not found", cmd);
		exit(1);
	}
}
void	free_data(char **arr)
{
	int	i;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}