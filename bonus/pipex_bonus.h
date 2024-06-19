/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:31 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/19 10:14:42 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct main
{
	int		ac;
	char	**av;
	char	**env;
} s_main;

char	*process_path( char **path, char ***args, char *cmd, char **envp);
char	*get_cmd(char **paths, char *cmd);

// Error handling
void	badfork(int pid, char *strerr);
void	badpath(char *path, char *cmd);
void	badopen(int fd, char *file);
void	badpipe(char *strerr);
void	badargs(char *exec);

void	forking(int *pid);
int		open_file(int type, char *file);
void	execute(char *path, char	**args, char **envp);
void	init_struct(s_main *st, int argc, char **argv, char **envp);

void	free_array(char **arr);
void	free_data(char *path, char **args);

void	first_child(s_main *st, int *fd);
void	middle_child(s_main *st, int *fd, int *fd2, char *cmd);
void	last_child(s_main *st, int *fd, int type);

void	process_children(s_main *st, int *fd);
void	get_input_process(s_main *st, int *fd);
void	keep_processing(s_main *st, int *fd, int type);

#endif