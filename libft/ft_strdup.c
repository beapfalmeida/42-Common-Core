/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:02:57 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/15 22:02:59 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

char	*ft_strdup(char *src)
{
	char	*new;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	new = malloc(src_len + 1);
	if (!new)
		return (0);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*int main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";

	printf("%s", ft_strdup(str));
	return (0);
}*/
