/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/13 17:55:34 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking(int *pid)
{
	*pid = fork();
	if (*pid == 0)
		badfork(*pid, strerror(errno));
}

void	multiargs(int argc, char **argv, char **envp, int *fd)
{
	int	i;
	int	pid;
	int	fd2[2];

	i = 3;
	forking(&pid);
	if (pid == 0)
		first_child(fd, envp, argv[1], argv[2]);
	else
		dup2(fd[0], STDIN_FILENO);
	while (i < argc - 2)
	{
		if (pipe(fd2) == -1)
			badpipe(strerror(errno));
		forking(&pid);
		if (pid == 0)
			middle_child(fd, fd2, envp, argv[i]);
		i++;
		fd[0] = fd2[0];
		dup2(fd[0], STDIN_FILENO);
		close(fd2[0]);
		close(fd2[1]);
		waitpid(pid, NULL, 0);
	}
	last_child(fd, envp, argv[argc - 1], argv[argc - 2]);
}
void	process_lim(char **argv, char **envp, int *fd, char *file)
{
	int		fd2[2];
	char	*line;
	int		pid;

	pipe(fd);
	forking(&pid);
	if (pid == 0)
	{
		line = get_next_line(0);
		while (line != NULL && ft_strnstr(line, argv[2], ft_strlen(line)) == NULL)
		{
			write(fd[1], line, ft_strlen(line));
			free(line);
			line = get_next_line(0);
		}
		close(fd[1]);
	}
	wait(NULL);
	if (pipe(fd2) == -1)
		badpipe(strerror(errno));
	dup2(fd[0], STDIN_FILENO);
	middle_child(fd, fd2, envp, argv[3]);
	dup2(fd2[0], STDIN_FILENO);
	last_child(fd2, envp, file, argv[4]);
	waitpid(0, NULL, 0);
	close(fd2[0]);
	close(fd2[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc < 5)
	{
		ft_printf("Please provide arguments of one of this forms:\n%s <infile> <cmd> ... <cmd> <outfile>\n %s", argv[0]);
		ft_printf("here_doc LIMITER <cmd> <cmd1> <outfile>\n", argv[0]);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc == 6)
			process_lim(argv, envp, fd, argv[5]);
		else
		{
			ft_printf("Please provide arguments of one of this forms:\n%s <infile> <cmd> ... <cmd> <outfile>\n %s", argv[0]);
			ft_printf("here_doc LIMITER <cmd> <cmd1> <outfile>\n", argv[0]);
		}
	}
	else
	{
		if (pipe(fd) == -1)
			perror(strerror(errno));
		multiargs(argc, argv, envp, fd);
	}
	close(fd[0]);
	close (fd[1]);	
	return (0);
}
