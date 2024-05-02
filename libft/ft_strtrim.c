/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:06:18 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/25 10:31:49 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check(char const *set, char c)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	st;
	char			*trim;
	int				e;

	st = 0;
	e = ft_strlen(s) - 1;
	while (s[st] && check(set, s[st]))
		st++;
	while (e >= 0 && check(set, s[e]))
		e--;
	if (st == ft_strlen(s) - 1)
		return (ft_strdup(""));
	trim = ft_substr(s, st, e - st + 1);
	return (trim);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "));
// 	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
// 	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", ""));
// 	printf("%s\n", ft_strtrim("lorem ipsum dolor sit amet", "tel"));
// 	printf("%s\n", ft_strtrim("     ", " "));
// }
