/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:14 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/26 12:02:14 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = ft_strlen(s);
	while (n > 0)
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n--;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
