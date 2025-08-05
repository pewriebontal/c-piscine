/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <mikhaing@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:20:43 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/22 18:23:35 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c >= '0' && c <= '9')
	{
		write(1, &c, sizeof(c));
		++c;
	}
}

// int main(void)
// {
// 	ft_print_numbers();
// }