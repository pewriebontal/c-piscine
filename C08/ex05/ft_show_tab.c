/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:13:02 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:13:02 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);

void	ptstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ptchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(long long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ptchar('-');
		putnbr(nb);
	}
	else if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		ptchar('0' + nb);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	count;

	count = 0;
	while (par[count].str != 0)
	{
		ptstr(par[count].str);
		ptstr("\n");
		putnbr(par[count].size);
		ptstr("\n");
		ptstr(par[count].copy);
		ptstr("\n");
		count++;
	}
}
