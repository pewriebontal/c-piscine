/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:11:12 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/04 18:03:51 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc;
	while (i > 1)
	{
		ft_putstr(argv[i - 1]);
		ft_putchar('\n');
		i--;
	}
}
