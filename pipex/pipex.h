/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:31 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/06 15:36:05 by bpaiva-f         ###   ########.fr       */
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
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

char	*process_path(char *cmd, char **envp);
char	*get_cmd(char **paths, char *cmd);
void	handle_errors(int c, char *strerr);
void	badpath(char *path, char *cmd);
void	free_array(char **arr);
void	free_data(char *path, char **args);
void	intermediate_funct( char **path, char ***args, char *cmd, char **envp);
void	first_child(int *fd, char **envp, char *file, char *cmd);
void	second_child(int *fd, char **envp, char *file, char *cmd);

#endif