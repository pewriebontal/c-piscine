/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:11:03 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/03 19:04:10 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use stdlib.h for malloc & free

/*
format:
./rush01 "col1top col2top col3top col4top
col1bottom col2bottom col3bottom col4bottom
row1left row2left row3left row4left
row1right row2right row3right row4right"

example:
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
*/

// reminders: cannot def > 5 functions in one file

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
 * @brief This is the main "manager" function. It directs the whole process:
 *        build the city, use logic to place easy buildings, then call the
 *        master detective (`solve`) to finish the job.
 *
 * @param clues The list of clues.
 * @param gridsize The size of the city.
 * @return void
 */
void	run_solver(int *clues, int gridsize)
{
	t_cell	**grid;

	grid = create_grid(gridsize);
	if (!grid)
	{
		print_error();
		return ;
	}
	lock_cells_from_simple_clues_cols(grid, clues, gridsize);
	lock_cells_from_simple_clues_rows(grid, clues, gridsize);
	lock_cells_from_advanced_clues(grid, clues, gridsize);
	if (solve(grid, clues, gridsize))
		ft_print_grid(grid, gridsize);
	else
		print_error();
	free_grid(grid, gridsize);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	gridsize;

	if (argc != 2 || !validate_input_and_get_size(argv[1], &gridsize))
	{
		print_error();
		return (1);
	}
	clues = malloc(sizeof(int) * (gridsize * gridsize));
	if (!clues)
	{
		print_error();
		return (1);
	}
	fill_clues_array(argv[1], clues, gridsize);
	run_solver(clues, gridsize);
	free(clues);
	return (0);
}
