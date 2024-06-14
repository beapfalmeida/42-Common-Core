/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/14 17:22:03 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking(int *pid)
{
	*pid = fork();
	if (*pid == 0)
		badfork(*pid, strerror(errno));
}

void	keep_processing(int argc, char **argv, char **envp, int *fd)
{
	int	i;
	int	fd2[2];
	int	pid;

	i = 3;
	while (i < argc - 2)
	{
		if (pipe(fd2) == -1)
			badpipe(strerror(errno));
		forking(&pid);
		if (pid == 0)
			middle_child(fd, fd2, envp, argv[i]);
		i++;
		fd[0] = fd2[0];
		fd[1] = fd2[1];
		dup2(fd[0], STDIN_FILENO);
		close(fd2[0]);
		close(fd2[1]);
		waitpid(pid, NULL, 0);
	}
	last_child(fd, envp, argv[argc - 1], argv[argc - 2]);
}

void	process_children(int argc, char **argv, char **envp, int *fd)
{
	int	pid;

	forking(&pid);
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	keep_processing(argc, argv, envp, fd);
}

void	get_input_process(int argc, char **argv, char **envp, int *fd)
{
	char	*str;
	char	*limiter;

	if (pipe(fd) == -1)
		badpipe(strerror(errno));
	limiter = ft_strjoin(argv[2], "\n");
	while (1)
	{
		str = get_next_line(0);
		write(fd[1], str, ft_strlen(str));
		if (!ft_strncmp(str, limiter, ft_strlen(str)))
			break ;
		free(str);
	}
	free(str);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	keep_processing(argc, argv, envp, fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc < 5)
		badargs(argv[0]);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc >= 6)
			get_input_process(argc, argv, envp, fd);
		else
			badargs(argv[0]);
	}
	else
	{
		if (pipe(fd) == -1)
			perror(strerror(errno));
		process_children(argc, argv, envp, fd);
	}
	close(fd[0]);
	close (fd[1]);
	return (0);
}
