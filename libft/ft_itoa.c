/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:00:19 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/26 15:20:28 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	countnum(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*free_data_zero(char *str)
{
	free(str);
	return (ft_strdup("0"));
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	num = n;
	len = countnum(num);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
		return (free_data_zero(str));
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num != 0 && len--)
	{
		str[len] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}
