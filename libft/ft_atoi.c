/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:44:59 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/15 21:45:04 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

/*int main(void)
{
    char str1[] = "   ---+--+1234ab567";
    char str2[] = "     -1098ahb";
    printf("Str1: %s, Result: %i\n", str1, ft_atoi(str1));
    printf("Original. Str1: %s, Result: %i\n", str1, atoi(str1));
    printf("Str2: %s, Result: %i\n", str2, ft_atoi(str2));
    printf("Str2: %s, Result: %i\n", str2, atoi(str2));
}*/
