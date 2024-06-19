/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/19 10:17:29 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_struct(s_main *st, int argc, char **argv, char **envp)
{
	st->ac = argc;
	st->av = argv;
	st->env = envp;
}

void	forking(int *pid)
{
	*pid = fork();
	if (*pid == 0)
		badfork(*pid, strerror(errno));
}

void	keep_processing(s_main *st, int *fd, int type)
{
	int	i;
	int	fd2[2];
	int	pid;

	i = 3;
	while (i < st->ac - 2)
	{
		if (pipe(fd2) == -1)
			badpipe(strerror(errno));
		forking(&pid);
		if (pid == 0)
			middle_child(st, fd, fd2, st->av[i]);
		i++;
		fd[0] = fd2[0];
		fd[1] = fd2[1];
		dup2(fd[0], STDIN_FILENO);
		close(fd2[0]);
		close(fd2[1]);
		waitpid(pid, NULL, 0);
	}
	last_child(st, fd, type);
}

void	process_children(s_main *st, int *fd)
{
	int	pid;
	int	status;

	forking(&pid);
	if (pid == 0)
		first_child(st, fd);
	else
	{
		dup2(fd[0], STDIN_FILENO);
		if (st->ac > 5)
			close(fd[1]);
		waitpid(pid, &status, 0);
	}
	keep_processing(st, fd, 1);
}

void	get_input_process(s_main *st, int *fd)
{
	char	*str;
	char	*limiter;

	if (pipe(fd) == -1)
		badpipe(strerror(errno));
	limiter = ft_strjoin(st->av[2], "\n");
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
	keep_processing(st, fd, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	s_main st;

	init_struct(&st, argc, argv, envp);
	if (argc < 5)
		badargs(argv[0]);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		
		if (argc >= 6)
			get_input_process(&st, fd);
		else
			badargs(argv[0]);
	}
	else
	{
		if (pipe(fd) == -1)
			badpipe(strerror(errno));
		process_children(&st, fd);
	}
	close(fd[0]);
	close (fd[1]);
	return (0);
}
