/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:17:51 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/17 15:49:23 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_data(char *path, char **args)
{
	free(path);
	free_array(args);
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

/// @brief checks if our command is in any of the paths
/// @param paths 
/// @param cmd 
/// @return the full path
char	*get_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
/// @brief Looks through the environment variables and splits the command possible paths into an array
/// @param path the path - ex usr/bin/grep
/// @param args is what we provide as argv[1], such as "grep a"
/// @param cmd our command, such as grep or ls
/// @param envp the environment variables
/// @return is the path variable
char	*process_path( char **path, char ***args, char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	*args = ft_split(cmd, ' ');
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			*path = get_cmd(paths, **args);
			free_array(paths);
			return (*path);
		}
		i++;
	}
	return (NULL);
}
