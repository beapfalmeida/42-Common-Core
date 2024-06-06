/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:14 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/06 15:40:30 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	intermediate_funct( char **path, char ***args, char *cmd, char **envp)
{
	*args = ft_split(cmd, ' ');
	*path = process_path(**args, envp);
	badpath(*path, cmd);
}

void	first_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path;
	char	**args;
	int		input_fd;

	intermediate_funct(&path, &args, cmd, envp);
	pid = fork();
	handle_errors(pid, strerror(errno));
	input_fd = open(file, O_RDONLY);
	handle_errors(input_fd, strerror(errno));
	if (pid == 0)
	{
		close(fd[0]);
		dup2(input_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(path, args, envp) == -1)
		{
			perror(strerror(errno));
			free_data(path, args);
			exit(1);
		}
	}
	close(input_fd);
	free_data(path, args);
}

void	second_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path;
	char	**args;
	int		input_fd;

	intermediate_funct(&path, &args, cmd, envp);
	pid = fork();
	handle_errors(pid, strerror(errno));
	input_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	handle_errors(input_fd, strerror(errno));
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(input_fd, STDOUT_FILENO);
		if (execve(path, args, envp) == -1)
		{
			perror(strerror(errno));
			free_data(path, args);
			exit(1);
		}
	}
	close(input_fd);
	free_data(path, args);
}
