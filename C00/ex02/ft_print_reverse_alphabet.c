/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <mikhaing@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:17:03 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/22 18:23:31 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c > 96)
	{
		write(1, &c, sizeof(c));
		--c;
	}
}

// int main(void)
// {
// 	ft_print_reverse_alphabet();
// }