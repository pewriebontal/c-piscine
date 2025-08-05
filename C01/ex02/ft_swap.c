/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <mikhaing@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:14:49 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/23 18:22:20 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	x;
// 	int	y;

// 	x = 2;
// 	y = 4;
// 	ft_swap(&x, &y);
// 	printf("%d%d\n", x, y);
// }
