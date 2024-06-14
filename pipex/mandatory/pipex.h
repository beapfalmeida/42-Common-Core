/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:31 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/14 09:59:44 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
void	free_array(char **arr);
void	free_data(char *path, char **args);
void	execute(char *path, char	**args, char **envp);
void	first_child(int *fd, char **envp, char *file, char *cmd);
void	second_child(int *fd, char **envp, char *file, char *cmd);

#endif