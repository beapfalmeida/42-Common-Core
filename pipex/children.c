# include "pipex.h"

void	first_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path = {NULL};
	char	**args = {NULL};
	int		input_fd;

	args = ft_split(cmd, ' ');
	path = process_path(args[0], envp);
	badpath(path, cmd);
	input_fd = open(file, O_RDONLY);
	handle_errors(input_fd, strerror(errno));
	pid = fork();
	handle_errors(pid, strerror(errno));
	if (pid == 0)
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

	args = ft_split(cmd, ' ');
	path = process_path(args[0], envp);
	badpath(path, cmd);
	input_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	handle_errors(input_fd, strerror(errno));
	pid = fork();
	handle_errors(pid, strerror(errno));
	if (pid == 0)
	{
		close(fd[1]);
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
