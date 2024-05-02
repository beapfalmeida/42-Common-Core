/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:56:54 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/23 12:42:12 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (!src || !dst)
		return (0);
	if (size == 0)
		return (slen);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
// int main(void)
// {
// 	char	*str = "hello !";
// 	char	buff1[0xF00];
// 	char	buff2[0xF00];

// 	memset(buff1, 'A', 20);
// 	memset(buff2, 'A', 20);
// 	printf("ORIGINAL: %zu\n", strlcpy(buff1, str, sizeof(buff1)));
// 	printf("MINHA: %zu\n", ft_strlcpy(buff2, str, sizeof(buff2)));
// }

// int main(void)
// {
// 	char	*dest;
// 	dest = (char *)malloc(sizeof(*dest) * 15);
// 	if (!dest)
// 		return (0);
// 	memset(dest, 0, 15);
// 	printf("%zu", ft_strlcpy(dest, "lorem ipsum", 3));
// 	printf("%s", dest);
// }
