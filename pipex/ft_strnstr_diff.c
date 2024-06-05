/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_diff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:04:49 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/06/05 11:37:44 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j]
			&& i + j < len && big[i + j] && little[j])
			j++;
		if (!little[j])
			return (1);
		i++;
	}
	return (0);
}
