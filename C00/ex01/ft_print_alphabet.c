/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <mikhaing@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:41 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/22 18:23:24 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c < 123)
	{
		write(1, &c, sizeof(c));
		++c;
	}
}

// int main(void)
// {
// 	ft_print_alphabet();
// }