/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/08 11:34:56 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	status = 0;
	int	pid;

	if (argc != 5)
	{
		ft_printf("Usage: %s <file1> <cmd1> <cmd2> <file2>\n", argv[0]);
		return (1);
	}
	if (pipe(fd) == -1)
		perror(strerror(errno));
	pid = fork();
	badfork(pid, strerror(errno));
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	if (WEXITSTATUS(status) && pid != 0)
 	{
		
		second_child(fd, envp, argv[4], argv[3]);
		//waitpid(0, NULL, 0);
	}
	waitpid(0, &status, 0);
	close(fd[0]);
	close (fd[1]);
	return (0);
}
