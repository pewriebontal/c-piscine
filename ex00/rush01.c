/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkai-yua <lkai-yua@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:47 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/26 16:57:09 by lkai-yua         ###   ########.fr       */
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
			ft_put_line(x, '/', '*', '\\');
		else if (row == y - 1)
			ft_put_line(x, '\\', '*', '/');
		else
			ft_put_line(x, '*', ' ', '*');
		ft_putchar('\n');
		++row;
	}
}
