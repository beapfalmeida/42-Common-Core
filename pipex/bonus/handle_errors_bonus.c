/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:11 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/14 10:36:03 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	badfork(int pid, char *strerr)
{
	if (pid == -1)
	{
		perror(strerr);
		exit(1);
	}
}

void	badpipe(char *strerr)
{
	perror(strerr);
	exit(1);
}

void	badpath(char *path, char *cmd)
{
	if (!path)
	{
		ft_printf("zsh: command not found: %s\n", cmd);
		exit(1);
	}
}

void	badopen(int input_fd, char *file)
{
	if (input_fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", file);
		exit(1);
	}
}

void	badargs(char *exec)
{
	ft_printf("Please provide arguments of one of this forms:\n%s <infile> <cmd> ... <cmd> <outfile>\n", exec);
	ft_printf("%s here_doc LIMITER <cmd> <cmd1> <outfile>\n", exec);
	exit(1);
}
