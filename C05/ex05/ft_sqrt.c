/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:10:46 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/04 17:49:06 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 46340 is the largest integer whose square (46340 * 46340)
 * does not exceed the maximum value of a 32-bit signed int (2,147,483,647).
 * This prevents integer overflow when calculating i * i in the loop.
 */
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_sqrt(4));
// }
