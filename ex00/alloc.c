/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:11:37 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:29:29 by mikhaing         ###   ########.fr       */
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

t_cell	**create_grid(int size)
{
	t_cell	**grid;
	int		i;
	int		j;

	grid = malloc(sizeof(t_cell *) * size);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = malloc(sizeof(t_cell) * size);
		if (!grid[i])
		{
			free_grid(grid, i);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			initialize_one_cell(&grid[i][j], i, j, size);
			j++;
		}
		i++;
	}
	return (grid);
}

void	free_grid(t_cell **grid, int n)
{
	int	i;
	int	j;

	if (!grid)
		return ;
	i = 0;
	while (i < n)
	{
		if (grid[i])
		{
			j = 0;
			while (j < n && grid[i][j].candidate)
			{
				free(grid[i][j].candidate);
				grid[i][j].candidate = NULL;
				j++;
			}
			free(grid[i]);
		}
		i++;
	}
	free(grid);
}

void	initialize_one_cell(t_cell *cell, int row, int col, int n)
{
	int	k;

	cell->x = col;
	cell->y = row;
	cell->height = 0;
	cell->candidate = malloc(sizeof(int) * n);
	k = 0;
	while (k < n)
	{
		cell->candidate[k] = k + 1;
		k++;
	}
}
