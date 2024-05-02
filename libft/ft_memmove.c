/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:56:16 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/23 11:54:04 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s < d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}

/*int main(void)
{
	char *src = "thanks to @apellicc for this test !\r\n\0";
 	char dst1[0xF0];
 	int size = 33;
 	char *r1 = memmove(dst1, src, size);
 	char *r2 = ft_memmove(dst1, src, size);
 	printf("ORIGINAL: %s\n", r1);
 	printf("MINE: %s\n", r2);

}*/
