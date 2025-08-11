/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:11:35 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/11 14:42:26 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;
	int	j;

	if (min >= max)
		return (NULL);
	i = max - min;
	j = 0;
	dest = (int *)malloc(sizeof(int) * i);
	if (NULL == dest)
		return (0);
	while (j < i)
	{
		dest[j] = min;
		j++;
		min++;
	}
	return (dest);
}

// int	main(void)
// {
// 	int	*rg;

// 	rg = ft_range(1, 9);
// 	ft_putintptr(rg);
// 	return (0);
// }
