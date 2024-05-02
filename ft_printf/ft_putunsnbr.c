/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:02:13 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/05/02 11:46:36 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countnum(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(unsigned int n)
{
	int		len;
	char	*str;
	unsigned long	num;

	num = n;
	len = countnum(num);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
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

int	ft_putunsnbr(unsigned int nb)
{
	char *str;
	int	i;

	str = ft_itoa(nb);
	i = ft_putstr(str);
	return (i);
}
