#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id1;
	int id2;
	int fd[2];

	//fd[0] read 
	// fd[1] write
	char *path ="/bin/sh";
	// if (argc != 5)
	// {
    //     printf("Usage: %s <shell_path1> <command1> <command2> <shell_path2>\n", argv[0]);
    //     return 1;
    // }
    if (pipe(fd) == -1)
	{
        perror("pipe");
        return 1;
    }
	id1 = fork();
	if (id1 == 0)
	{
		char *args[] = {"sh", "-c", argv[2], NULL};
		dup2(fd[0], 0);
		close(fd[0]);
		close (fd[1]);
		if (execv(path, args) == -1)
		{
			perror("execv");
			return (1);
		}
	}
	else
		waitpid(id1, NULL , 0);
	id2 = fork();
	if (id2 == 0)
	{
		char *args[] = {"sh", "-c", argv[3], NULL};
		dup2(fd[1], 1);
		close(fd[0]);
		close (fd[1]);
		if (execv(path, args) == -1)
		{
			perror("execv");
			return (1);
		}
	}
	else
		waitpid(id2, NULL, 0);
	close(fd[0]);
	close (fd[1]);
	return (0);
}