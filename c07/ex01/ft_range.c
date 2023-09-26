/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:35 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:11:35 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;
	int	j;

	if (min >= max)
	{
		return (NULL);
	}
	i = max - min;
	j = 0;
	dest = (int *)malloc(sizeof(int) * i);
	if (dest == NULL)
	{
		return (0);
	}
	while (j < i)
	{
		dest[j] = min;
		j++;
		min++;
	}
	return (dest);
}
/*
int	main(void)
{
	int	*rg;

	rg = ft_range(1, 9);
	ft_putintptr(rg);
	return (0);
}
*/
