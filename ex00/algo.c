/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:15:37 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:29:17 by mikhaing         ###   ########.fr       */
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

int	solve(t_cell **grid, int *clues, int n)
{
	int	row;
	int	col;
	int	i;
	int	num_to_try;

	if (!find_best_empty_cell(grid, &row, &col, n))
		return (is_solution_valid(grid, clues, n));
	i = 0;
	while (i < n)
	{
		num_to_try = grid[row][col].candidate[i];
		if (num_to_try != 0)
		{
			grid[row][col].height = num_to_try;
			print_permutation(grid, n);
			toggle_candidates(&grid[row][col], grid, n, 0);
			if (solve(grid, clues, n))
				return (1);
			toggle_candidates(&grid[row][col], grid, n, 1);
			grid[row][col].height = 0;
		}
		i++;
	}
	return (0);
}

void	lock_cells_from_simple_clues_cols(t_cell **grid, int *clues, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (clues[i] == 1)
			place_and_lock(&grid[0][i], grid, n, n);
		if (clues[n + i] == 1)
			place_and_lock(&grid[n - 1][i], grid, n, n);
		if (clues[i] == n)
		{
			j = -1;
			while (++j < n)
				place_and_lock(&grid[j][i], grid, j + 1, n);
		}
		if (clues[n + i] == n)
		{
			j = -1;
			while (++j < n)
				place_and_lock(&grid[n - 1 - j][i], grid, j + 1, n);
		}
		i++;
	}
}

void	lock_cells_from_simple_clues_rows(t_cell **grid, int *clues, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (clues[2 * n + i] == 1)
			place_and_lock(&grid[i][0], grid, n, n);
		if (clues[3 * n + i] == 1)
			place_and_lock(&grid[i][n - 1], grid, n, n);
		if (clues[2 * n + i] == n)
		{
			j = -1;
			while (++j < n)
				place_and_lock(&grid[i][j], grid, j + 1, n);
		}
		if (clues[3 * n + i] == n)
		{
			j = -1;
			while (++j < n)
				place_and_lock(&grid[i][n - 1 - j], grid, j + 1, n);
		}
		i++;
	}
}

void	lock_cells_from_advanced_clues(t_cell **grid, int *clues, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (clues[i] + clues[n + i] == n + 1)
			place_and_lock(&grid[clues[i] - 1][i], grid, n, n);
		if (clues[2 * n + i] + clues[3 * n + i] == n + 1)
			place_and_lock(&grid[i][clues[2 * n + i] - 1], grid, n, n);
		if (clues[i] == 2)
			grid[0][i].candidate[n - 1] = 0;
		if (clues[n + i] == 2)
			grid[n - 1][i].candidate[n - 1] = 0;
		if (clues[2 * n + i] == 2)
			grid[i][0].candidate[n - 1] = 0;
		if (clues[3 * n + i] == 2)
			grid[i][n - 1].candidate[n - 1] = 0;
		i++;
	}
}

int	find_best_empty_cell(t_cell **grid, int *row, int *col, int n)
{
	int	r_c[2];
	int	min_cand;
	int	*best[3];

	min_cand = n + 1;
	*row = -1;
	best[0] = row;
	best[1] = col;
	best[2] = &min_cand;
	r_c[0] = 0;
	while (r_c[0] < n)
	{
		r_c[1] = 0;
		while (r_c[1] < n)
		{
			if (grid[r_c[0]][r_c[1]].height == 0)
				check_and_update_best_cell(grid, r_c, best, n);
			r_c[1]++;
		}
		r_c[0]++;
	}
	return (*row != -1);
}
