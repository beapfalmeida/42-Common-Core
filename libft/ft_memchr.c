/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:53:43 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/15 21:53:47 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("ORIGINAL: %s\n", (char *)memchr(tab, -1, 7));
	printf("MINHA: %s", (char *)ft_memchr(tab, -1, 7));
}*/
