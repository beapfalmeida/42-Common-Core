/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:57:36 by bpaiva-f          #+#    #+#             */
/*   Updated: 2024/04/23 11:54:16 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 
#include <string.h> 

void	*ft_memset(void	*s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned int	i;

	arr = s;
	i = 0;
	while (i < n)
	{
		arr[i] = c;
		i++;
	}
	return (s);
}

/*int main(void)
{
	int n = 10; 
	char arr[n];
	
	ft_memset(arr, 10, n*sizeof(arr[0]));
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
}*/
