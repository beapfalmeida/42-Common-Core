/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:31 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/14 10:34:03 by bpaiva-f         ###   ########.fr       */
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
# include "../ft_printf/ft_printf.h"

char	*process_path( char **path, char ***args, char *cmd, char **envp);
char	*get_cmd(char **paths, char *cmd);

void	badfork(int pid, char *strerr);
void	badpath(char *path, char *cmd);
void	badopen(int input_fd, char *file);
void	forking(int *pid);
void	badpipe(char *strerr);
void	badargs(char *exec);

void	free_array(char **arr);
void	free_data(char *path, char **args);

void	execute(char *path, char	**args, char **envp);
void	first_child(int *fd, char **envp, char *file, char *cmd);
void	middle_child(int *fd, int *fd2, char **envp, char *cmd);
void	last_child(int *fd, char **envp, char *file, char *cmd);

void	process_children(int argc, char **argv, char **envp, int *fd);
void	get_input_process(int argc, char **argv, char **envp, int *fd);
void	keep_processing(int argc, char **argv, char **envp, int *fd);

#endif