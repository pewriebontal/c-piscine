/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:23:09 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 19:03:53 by aiyahaya         ###   ########.fr       */
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
 * @brief This function updates our notepads. When we place a building on a
 *        lot, this function goes to all the other empty lots in the same row
 *        and same column and crosses that building's height off their list of
 *        possible candidates. It can also undo this process if we have to
 *        backtrack (the 'restore' parameter tells it what to do).
 *
 * @param cell The specific lot where we just placed or removed a building.
 * @param grid The entire city map.
 * @param n The size of our city (e.g., 4 for a 4x4 city).
 * @param restore A switch. If it's 0, we are placing a building and should
 *                *remove* its height from other candidates. If it's 1, we are
 *                backtracking and should *add* its height back.
 * @return void
 */
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

/**
 * @brief This is our "locking" function. When we are 100% sure a building
 *        belongs on a certain lot, this function places it there. It sets the
 *        lot's height and erases all other possibilities from that lot's
 *        personal notepad (`candidate` list). Then, it calls another function
 *        to update the notepads of all the other lots on the same streets.
 *
 * @param cell The specific lot we want to lock a building into.
 * @param grid The entire city map.
 * @param num The height of the building we are locking in.
 * @param n The size of our city.
 * @return void
 */
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

/**
 * @brief A small helper that checks one lot to see if it's a better choice
 *        for our solver to work on next than our current best choice.
 *
 * @param grid The city map.
 * @param coords The [row, column] address of the lot 
 * 		we are currently looking at.
 * @param best A collection of pointers that keeps track of
		the best lot found so far.
 * @param n The size of our city.
 * @return void
 */
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

/**
 * @brief Reads the numbers from the input string and puts them into our
 *        integer array of clues.
 * 
 * @param arg The text string given to the program.
 * @param clues The integer array where we will store the clues.
 * @param gridsize The size of our city.
 * @return void
 */
void	fill_clues_array(char *arg, int *clues, int gridsize)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] && count < (gridsize * gridsize))
	{
		if (arg[i] >= '1' && arg[i] <= ('0' + gridsize))
		{
			clues[count] = arg[i] - '0';
			count++;
		}
		i++;
	}
}
