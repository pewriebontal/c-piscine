/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:23:09 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:30:35 by mikhaing         ###   ########.fr       */
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

void	toggle_candidates(t_cell *cell, t_cell **grid, int n, int restore)
{
	int	i;
	int	num;
	int	value_to_set;

	num = cell->height;
	if (restore)
		value_to_set = num;
	else
		value_to_set = 0;
	i = 0;
	while (i < n)
	{
		if (grid[cell->y][i].height == 0)
			grid[cell->y][i].candidate[num - 1] = value_to_set;
		if (grid[i][cell->x].height == 0)
			grid[i][cell->x].candidate[num - 1] = value_to_set;
		i++;
	}
}

void	place_and_lock(t_cell *cell, t_cell **grid, int num, int n)
{
	int	k;

	if (cell->height == 0)
	{
		cell->height = num;
		k = 0;
		while (k < n)
		{
			if (cell->candidate[k] != num)
				cell->candidate[k] = 0;
			k++;
		}
		toggle_candidates(cell, grid, n, 0);
	}
}

void	check_and_update_best_cell(t_cell **grid, int *coords, int **best,
		int n)
{
	int	cand_count;
	int	i;

	cand_count = 0;
	i = 0;
	while (i < n)
	{
		if (grid[coords[0]][coords[1]].candidate[i] != 0)
			cand_count++;
		i++;
	}
	if (cand_count < *best[2])
	{
		*best[2] = cand_count;
		*best[0] = coords[0];
		*best[1] = coords[1];
	}
}

void	fill_clues_array(char *arg, int *clues, int gridsize)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] && count < (gridsize * 4))
	{
		if (arg[i] >= '1' && arg[i] <= ('0' + gridsize))
		{
			clues[count] = arg[i] - '0';
			count++;
		}
		i++;
	}
}
