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
		if (access(command, 0)==0)
			return (command);
		paths++;
	}
	return (NULL);
}
char	*process_path(char *cmd, char **envp)
{
	char 	*init_path;
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strcmp(envp[i],"PATH", 4))
		{
			paths = ft_split(envp[i], ":");
			return (get_cmd(paths, cmd));
		}
    }
	return (NULL);
}

void	first_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path = {NULL};
	char	**args = {NULL};
	int		input_fd;

	args = ft_split(cmd, ' ');
	path = process_path(args[0], envp);
	if (!path)
		return (0); //adicionar tratamento de erros para comandos invalidos
	input_fd = open(file, O_RDONLY);
	if (input_fd == -1)
		perror(strerror(errno));
	pid = fork();
	if (pid == -1)
		perror(strerror(errno));
	if (pid ==0)
	{
		close(fd[0]);
		dup2(input_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(path, args, envp) == -1)
		{
			perror(strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	close(input_fd);
}

void	second_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path = {NULL};
	char	**args = {NULL};
	int		input_fd;

	input_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	args = ft_split(cmd, ' ');
	path = process_path(args[0], envp);
	if (!path)
	return (0); //adicionar tratamento de erros para comandos invalidos
	if (input_fd == -1)
		perror(strerror(errno));
	pid = fork();
	if (pid == -1)
		perror(strerror(errno));
	if (pid ==0)
	{
		close (fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(input_fd, STDOUT_FILENO);
		if (execve(path, args, envp) == -1)
		{
			perror(strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	close(input_fd);
}

int	main(int argc, char **argv, char **envp)
{
	int fd[2];
	char	*file;
	char	*cmd;

	if (argc != 5)
        printf("Usage: %s <shell_path1> <command1> <command2> <shell_path2>\n", argv[0]);
	if (pipe(fd) == -1)
		perror(strerror(errno));
	first_child(fd, envp, argv[1], argv[2]);
	second_child(fd, envp, argv[4], argv[3]);
	waitpid(0, NULL, 0);
	close(fd[0]);
	close (fd[1]);
	return (0);
}
