/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchoo <zchoo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:54 by zchoo             #+#    #+#             */
/*   Updated: 2025/07/26 15:51:19 by zchoo            ###   ########.fr       */
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
		if (row == 0)
			ft_put_line(x, 'A', 'B', 'C');
		else if (row == y - 1)
			ft_put_line(x, 'C', 'B', 'A');
		else
			ft_put_line(x, 'B', ' ', 'B');
		ft_putchar('\n');
		++row;
	}
}
