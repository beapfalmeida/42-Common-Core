#ifndef PIPEX_H
#define PIPEX_H

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
void	free_data(char **arr);
void	first_child(int *fd, char **envp, char *file, char *cmd);
void	second_child(int *fd, char **envp, char *file, char *cmd);

#endif