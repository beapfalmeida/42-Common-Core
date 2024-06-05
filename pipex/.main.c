# include "pipex.h"
int main(void)
{
	char	*path = "/usr/bin/ls";
	char	*argVec[] = {"ls", "-l", "test1.txt", NULL};
	char	*envVec[] = {NULL};

	if(execve(path, argVec, envVec) == -1)
	{
		perror("execve");
	}
	printf("Oops something went wrong!");
}