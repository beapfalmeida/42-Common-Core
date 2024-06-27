/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:14 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/27 13:05:50 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/// @brief function to set the diferent open options
/// @param type 0 is for normal output; 1 is for here_doc
int	open_file(int type, char *file)
{
	int output_fd;
	if (type == 0)
		output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		output_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (output_fd);
}

void	execute(char *path, char	**args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		perror(strerror(errno));
		free_data(path, args);
		exit(1);
	}
}

///@brief This is a function that processes the first command of a pipe. It receives an input file and writes into a pipe.
///@param fd file discriptor of your input file
///@param envp environment variables
///@param file the name of your input file
///@param cmd your shell command, such as grep, ls...
void	first_child(s_main *st, int *fd)
{
	
	char	*path;
	char	**args;
	int		input_fd;
	char	*file;
	char	*cmd;

	file = st->av[1];
	cmd = st->av[2];
	input_fd = 0;
	input_fd = open(file, O_RDONLY);
	badopen(input_fd, file);
	process_path(&path, &args, cmd, st->env);
	badpath(path, cmd);
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(path, args, st->env);
}

///@brief This is a function that processes a middle command of a pipe. It reads from a pipe and writes into an other pipe.
///@param fd file discriptor from which to read
///@param fd2 file discriptor in which to write
///@param envp environment variables
///@param cmd your shell command, such as grep, ls...
void	middle_child(s_main *st, int *fd, int *fd2, char *cmd)
{
	char	*path;
	char	**args;

	process_path(&path, &args, cmd, st->env);
	badpath(path, cmd);
	dup2(fd2[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd2[0]);
	execute(path, args, st->env);
}

///@brief This is a function that processes the first command of a pipe. It reads from a pipe and writes into the output file.
///@param fd file discriptor from which to read
///@param file the name of your output file
///@param envp environment variables
///@param cmd your shell command, such as grep, ls...
void	last_child(s_main *st, int *fd, int type)
{
	int		pid;
	char	*path;
	char	**args;
	int		output_fd;
	char	*file;
	char	*cmd;

	cmd = st->av[st->ac -2];
	file = st->av[st->ac -1];
	pid = fork();
	if (pid == 0)
		badfork(pid, strerror(errno));
	output_fd = open_file(type, file);
	badopen(output_fd, file);
	process_path(&path, &args, cmd, st->env);
	if (pid == 0)
	{
		badpath(path, cmd);
		close(fd[1]);
		dup2(output_fd, STDOUT_FILENO);
		execute(path, args, st->env);
	}
	close(output_fd);
	free_data(path, args);
}
