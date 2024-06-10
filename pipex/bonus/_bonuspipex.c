/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonuspipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/10 13:53:11 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonuspipex.h"

void forking(int *pid)
{
	*pid = fork();
	if (*pid == 0)
		badfork(*pid, strerror(errno));
}

void	multiargs(int argc, char **argv, char **envp, int *fd)
{
	int	fd2[2];
	int	status;
	int i;
	int	pid;
	int flag;

	i = 3;
	status = 0;
	flag = 0;
	forking(&pid);
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		while (i < argc - 2)
		{
			if (!flag)
			{
				middle_child(fd, fd2, envp, argv[i]);
				flag = 1;
			}
			else
			{
				middle_child(fd2, fd, envp, argv[i]);
				flag = 0;
			}
			i++;
		}
		forking(&pid);
		if (pid == 0)
		{
			if (argc % 2 == 0)
				last_child(fd2, envp, argv[argc - 1], argv[argc - 2]);
			else
				last_child(fd, envp, argv[argc - 1], argv[argc - 2]);
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(fd2[0]);
	close(fd2[1]);
}

void	mandatory_pipex(char **argv, char **envp, int *fd)
{
	int pid;
	int status;

	status = 0;
	pid = fork();
	badfork(pid, strerror(errno));
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0 && pid != 0)
		second_child(fd, envp, argv[4], argv[3]);
	close(fd[0]);
	close (fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc < 5)
	{
		ft_printf("Please provide at least 2 commands: %s <file1> <cmd1> <cmd2> ... <file2>\n", argv[0]); //ver isto
		return (1);
	}
	if (pipe(fd) == -1)
		perror(strerror(errno));
	if (argc > 5)
		multiargs(argc, argv, envp, fd);
	else
		mandatory_pipex(argv, envp, fd);
	
	return (0);
}
