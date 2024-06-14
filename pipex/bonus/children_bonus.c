/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:14 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/14 10:34:20 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char *path, char	**args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		perror(strerror(errno));
		free_data(path, args);
		exit(1);
	}
}

void	first_child(int *fd, char **envp, char *file, char *cmd)
{
	char	*path;
	char	**args;
	int		input_fd;

	input_fd = 0;
	input_fd = open(file, O_RDONLY);
	badopen(input_fd, file);
	process_path(&path, &args, cmd, envp);
	badpath(path, cmd);
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(path, args, envp);
}

void	middle_child(int *fd, int *fd2, char **envp, char *cmd)
{
	char	*path;
	char	**args;
	process_path(&path, &args, cmd, envp);
	badpath(path, cmd);
	dup2(fd2[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd2[0]);
	execute(path, args, envp);
}

void	last_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path;
	char	**args;
	int		output_fd;

	pid = fork();
	if (pid == 0)
		badfork(pid, strerror(errno));
	output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	process_path(&path, &args, cmd, envp);
	if (pid == 0)
	{
		badpath(path, cmd);
		close(fd[1]);
		dup2(output_fd, STDOUT_FILENO);
		execute(path, args, envp);
	}
	close(output_fd);
	free_data(path, args);
}
