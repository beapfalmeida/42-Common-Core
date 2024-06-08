/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:14 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/08 11:09:35 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	close_and_dup(int *fd, int input_fd)
{
	close(fd[0]);
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

void	open_infile(int input_fd, char	*file)
{
	input_fd = open(file, O_RDONLY);
	if (input_fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", file);
		exit(1);
	}
}
void	first_child(int *fd, char **envp, char *file, char *cmd)
{
	char	*path;
	char	**args;
	int		input_fd;

	input_fd = 0;
	
	open_infile(input_fd, file);
	process_path(&path, &args, cmd, envp);
	badpath(path, cmd);
	close_and_dup(fd, input_fd);
	if (execve(path, args, envp) == -1)
	{
		perror(strerror(errno));
		free_data(path, args);
		exit(1);
	}
	//free_data(path, args);
}

void	second_child(int *fd, char **envp, char *file, char *cmd)
{
	int		pid;
	char	*path;
	char	**args;
	int		input_fd;

	printf("hi");
	pid = fork();
	if (pid == 0)
		badfork(pid, strerror(errno));
	input_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	process_path(&path, &args, cmd, envp);
	badpath(path, cmd);
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
