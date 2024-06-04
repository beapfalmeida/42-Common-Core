#include "pipex.h"

// char	**process_cmd(char *file, char *cmd)
// {
// 	// char	*temp1;
// 	char	**args;

// 	// temp1 = ft_strjoin(cmd, " ");
// 	// temp1 = ft_strjoin(temp1, file);
// 	;
// 	return (args);
// }
char	*process_path(char *arg)
{
	char *init_path;
	char	*path;

	init_path = "/usr/bin/";
	path = ft_strjoin(init_path, arg);
	return (path);
}

void	execute_function(int *fd, char **envp, char *file, char *cmd, int first)
{
	int pid;
	char	*path = {NULL};
	char	**args = {NULL};
	char id;
	if (first)
		id = open(file, O_RDONLY);
	else
		id = open(file, O_WRONLY);
	if (id == -1)
				perror("open");
	pid = fork();
	if (pid == -1)
		perror("open");
	if (pid ==0)
	{
		if (first)
		{
			close(fd[0]);
			// id = open(file, O_RDONLY);
			// if (id == -1)
			// 	perror("open");
			dup2(id, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			args = ft_split(cmd, ' ');
			path = process_path(args[0]);
		}
		else
		{
			close (fd[1]);
			// id = open(file, O_WRONLY);
			dup2(fd[0], STDIN_FILENO);
			dup2(id, STDOUT_FILENO);
			args = ft_split(cmd, ' ');
			path = process_path(args[0]);
		}
		if (execve(path, args, envp) == -1)
		{
				perror("execv");
			exit(EXIT_FAILURE);
		}
	}
	//close(fd[0]);
	//close (fd[1]);
	close(id);
}

int	main(int argc, char **argv, char **envp)
{
	//int	id1;
	//int id2;
	int fd[2];
	char	*file;
	char	*cmd;

	if (argc != 5)
        printf("Usage: %s <shell_path1> <command1> <command2> <shell_path2>\n", argv[0]);
	if (pipe(fd) == -1)
		perror("pipe");
	// id1 = fork();
	// if (id1 == 0)
		execute_function(fd, envp, argv[1], argv[2], 1);
	//waitpid(id1, NULL, 0);
	// id2 = fork();
	// if (id2 == 0)
		execute_function(fd, envp, argv[4], argv[3], 0);
	waitpid(0, NULL, 0);
	close(fd[0]);
	close (fd[1]);
	return (0);
}
