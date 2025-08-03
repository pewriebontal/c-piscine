/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:13:16 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:30:29 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// |
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//

#include "rush01.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int	is_solution_valid(t_cell **grid, int *clues, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!check_top_view(grid, clues, n, i) || !check_bottom_view(grid,
				clues, n, i) || !check_left_view(grid, clues, n, i)
			|| !check_right_view(grid, clues, n, i))
			return (0);
		i++;
	}
	return (1);
}

// ASCII index for digits: 48-57
int	ft_strlen(char *c)
{
	int		i;
	int		count;
	char	*result;

	i = 0;
	count = 0;
	result = c;
	while (c[i])
	{
		if (c[i] >= 48 && c[i] <= 57)
		{
			result[count] = c[i];
			count++;
		}
		i++;
	}
	result[count] = '\0';
	return (count);
}

int	ft_gridsize(int x)
{
	int	i;
	int	y;

	i = 9;
	y = 0;
	while (i >= 4)
	{
		if (i * i == x)
			y = i;
		i--;
	}
	return (y);
}

int	validate_input_and_get_size(char *arg, int *gridsize)
{
	int	num_count;
	int	i;

	num_count = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			num_count++;
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (num_count == 0 || num_count % 4 != 0)
		return (0);
	*gridsize = num_count / 4;
	if (*gridsize < 4 || *gridsize > 9)
		return (0);
	return (1);
}
