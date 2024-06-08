/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:11 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/08 11:20:50 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	badfork(int pid, char *strerr)
{
	if (pid == -1)
	{
		perror(strerr);
		exit(1);
	}
}

void	badpath(char *path, char *cmd)
{
	if (!path)
	{
		ft_printf("zsh: command not found: %s\n", cmd);
		exit(1);
	}
}
void	badopen(int input_fd, char *file)
{
	if (input_fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", file);
		exit(1);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_data(char *path, char **args)
{
	free(path);
	free_array(args);
}
