/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:15:37 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:41:02 by mikhaing         ###   ########.fr       */
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

/**
 * @brief This is the heart of the program, the master detective. It works
 *        like someone solving a maze.
 *        1. Find the best empty lot to work on.
 *        2. Try placing the first possible building from its notepad.
 *        3. Call itself to go solve the *rest* of the maze.
 *        4. If it works, great! We're done.
 *        5. If not, it's a dead end. BACKTRACK: take the building out, and
 *           try the next one on the notepad.
 *
 * @param grid The city map.
 * @param clues The list of clues.
 * @param n The size of our city.
 * @return 1 if it found a solution, 0 if it was a dead end.
 */
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

/**
 * @brief This function uses the two easiest clues to solve parts of the puzzle
 *        for the up-and-down streets (columns).
 *        - If a clue is '1', the tallest building (`n`) must be right in front.
 *        - If a clue is `n`, the buildings must be in a perfect ascending
 *          line from that viewpoint (1, 2, 3, ..., n).
 *
 * @param grid The city map.
 * @param clues The list of numbers from the puzzle box.
 * @param n The size of our city.
 * @return void
 */
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

/**
 * @brief This function does the same thing as the one above, but for the
 *        left-and-right streets (rows).
 *
 * @param grid The city map.
 * @param clues The list of numbers from the puzzle box.
 * @param n The size of our city.
 * @return void
 */
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

/**
 * @brief This function uses some clever math and logic to find more
 *        guaranteed building placements.
 *
 *        Math Rule: `clue_from_front + clue_from_back = n + 1`
 *        If you look at a street from the front and from the back, and the
 *        number of buildings you see adds up to `n + 1`, you can figure out
 *        exactly where the tallest building (`n`) on that street is!
 *
 *        Logic Rule: If a clue is `2`, it means the tallest building (`n`)
 *        can't be in the very first spot (otherwise the clue would be `1`).
 *        So we can cross `n` off the notepad for that first lot.
 *
 * @param grid The city map.
 * @param clues The list of numbers from the puzzle box.
 * @param n The size of our city.
 * @return void
 */
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

/**
 * @brief This is a smart helper for our solver. Instead of picking a random
 *        empty lot, it scans the whole grid to find the one with the *fewest*
 *        possible building choices left on its notepad. Solving this one first
 *        helps us find mistakes much faster.
 *
 * @param grid The city map.
 * @param row A pointer to a variable where we'll store the best row found.
 * @param col A pointer to a variable where we'll store the best column found.
 * @param n The size of our city.
 * @return 1 if it found an empty lot, or 0 if the city is already full.
 */
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
