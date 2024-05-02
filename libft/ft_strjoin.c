/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:50:45 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/23 11:56:06 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	tlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tlen = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((tlen + 1) * sizeof(char));
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

/*int main(void)
{
	char	s1[] = "\0orem ipsum";
	char	s2[] = "\0olor sit amet";
	
	printf("%s", ft_strjoin(s1, s2));
}*/
