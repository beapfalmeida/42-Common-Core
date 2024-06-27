/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/27 13:12:24 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	status;
	int	pid;

	status = 0;
	if (argc != 5)
	{
		ft_printf("Usage: %s <infile> <cmd1> <cmd2> <outfile>\n", argv[0]);
		return (1);
	}
	if (pipe(fd) == -1)
		perror(strerror(errno));
	pid = fork();
	badfork(pid, strerror(errno));
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	second_child(fd, envp, argv[4], argv[3]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	return(0);
}
