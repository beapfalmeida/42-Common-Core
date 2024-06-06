#include "pipex.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		free_data(paths);
		if (access(command, 0) == 0)
			return (command);
		paths++;
	}
	return (NULL);
}
char	*process_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i],"PATH", 4) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (get_cmd(paths, cmd));
		}
		i++;
    }
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (argc != 5)
        ft_printf("Usage: %s <shell_path1> <command1> <command2> <shell_path2>\n", argv[0]);
	if (pipe(fd) == -1)
		perror(strerror(errno));
	first_child(fd, envp, argv[1], argv[2]);
	second_child(fd, envp, argv[4], argv[3]);
	waitpid(0, NULL, 0);
	close(fd[0]);
	close (fd[1]);
	return (0);
}
