/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:54 by zchoo             #+#    #+#             */
/*   Updated: 2025/07/26 15:21:47 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	is_wall(int x, int y, int x_max, int y_max)
{
	return (x == 0 || x == x_max || y == 0 || y == y_max);
}

int	is_corner(int x, int y, int x_max, int y_max)
{
	int	rtn;

	rtn = 0;
	if ((x == 0 && y == 0) || (x == 0 && y == y_max))
	{
		rtn = 1;
	}
	else if ((x == x_max && y == 0) || (x == x_max && y == y_max))
	{
		rtn = 1;
	}
	return (rtn);
}

void	print(int x, int y, int x_max, int y_max)
{
	if (is_corner(x, y, x_max, y_max))
	{
		if ((x == 0 && y == y_max && y != 0))
			ft_putchar('C');
		else if (x == x_max && y == 0 && x != 0)
			ft_putchar('C');
		else if ((x == 0 && y == 0) || (x == x_max && y == y_max))
			ft_putchar('A');
		else
			ft_putchar('C');
	}
	else if (is_wall(x, y, x_max, y_max))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	_y;
	int	_x;

	_y = 0;
	while (_y < y)
	{
		_x = 0;
		while (_x < x)
		{
			print(_y, _x, y - 1, x - 1);
			_x++;
		}
		ft_putchar(10);
		_y++;
	}
}
