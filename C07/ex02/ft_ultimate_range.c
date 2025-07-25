/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:41 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/25 08:30:44 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = max - min;
	j = 0;
	dest = (int *)malloc(sizeof(int) * i);
	if (dest == NULL)
	{
		return (-1);
	}
	while (j < (i))
	{
		dest[j] = min;
		j++;
		min++;
	}
	*range = dest;
	return (i);
}
/*
int	main(void)
{
	int	*rg;

	//Test not working!
	rg = ft_range(1, 9);
	ft_putintptr(rg);
	return (0);
}
*/
