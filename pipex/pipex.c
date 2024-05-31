#include "pipex.h"

int	main(int argc, char **argv)
{
	int	id1;
	int id2;
	int fd[2];

	//fd[0] read 
	// fd[1] write
	char *init_path;
	char	*path1;
	char	*path2;
	char	**args1;
	char	**args2;
	int i;

	if (argc != 5)
	{
        printf("Usage: %s <shell_path1> <command1> <command2> <shell_path2>\n", argv[0]);
        return 1;
    }
	init_path ="/usr/bin/";
	args1 = ft_split(argv[2], ' ');
	args2 = ft_split(argv[3], ' ');
	path1 = ft_strjoin(init_path, args1[0]);
	path2 = ft_strjoin(init_path, args2[0]);
	if (!path1 || !path2) 
	{
        printf("Error: Failed to join paths\n");
        return 1;
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
    }
	id1 = fork();
	if (id1 == 0)
		printf("hello\n");

	if (id1 == 0)
	{
		//dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close (fd[1]);
		printf("hi");
		return (1);
		// if (execv(path1, args1) == -1)
		// {
		// 	perror("execv");
		// 	return (1);
		// }
	}
	waitpid(id1, NULL , 0);
	id2 = fork();
	if (id2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close (fd[1]);
		// if (execv(path2, args2) == -1)
		// {
		// 	perror("execv");
		// 	return (1);
		// }
	}
	waitpid(id2, NULL, 0);
	close(fd[0]);
	close (fd[1]);
	free(path1);
    free(path2);
    free(args1);
    free(args2);
	return (0);
}