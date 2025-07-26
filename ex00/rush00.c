/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:43 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/26 15:24:19 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_line(int width, char left, char mid, char right)
{
	int	i;

	if (width <= 0)
		return ;
	ft_putchar(left);
	i = 1;
	while (i < width - 1)
	{
		ft_putchar(mid);
		++i;
	}
	if (width > 1)
		ft_putchar(right);
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0 || row == y - 1)
			ft_put_line(x, 'o', '-', 'o');
		else
			ft_put_line(x, '|', ' ', '|');
		ft_putchar('\n');
		++row;
	}
}
