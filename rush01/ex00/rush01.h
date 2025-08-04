/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:04:33 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:27:57 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//                    _oo0oo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   0\  =  /0
//                 ___/`---'\___
//               .' \\|     |// '.
//              / \\|||  :  |||// |
//             / _||||| -:- |||||- \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |_/ |
//            \  .-\__  '-'  ___/-. /
//          ___'. .'  /--.--\  `. .'___
//       ."" '<  `.___\_<|>_/___.' >' "".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `_.   \_ __\ /__ _/   .-` /  /
//  =====`-.____`.___ \_____/___.-`___.-'=====
//                    `=---='

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//            佛祖保佑         永无BUG

#ifndef RUSH01_H
# define RUSH01_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"

typedef struct s_cell
{
	int	x;
	int	y;
	int	height;
	int	*candidate;
}		t_cell;

// rush01.c
void	run_solver(int *clues, int gridsize);
int		main(int argc, char **argv);

// print.c
void	print_permutation(t_cell **grid, int n);
void	ft_print_grid(t_cell **grid, int n);

// alloc.c
t_cell	**create_grid(int size);
void	free_grid(t_cell **grid, int n);
void	initialize_one_cell(t_cell *cell, int row, int col, int n);

// utils.c
void	print_error(void);
int		is_solution_valid(t_cell **grid, int *clues, int n);
int		ft_strlen(char *c);
int		ft_gridsize(int x);
int		validate_input_and_get_size(char *arg, int *gridsize);

// utils1.c
void	toggle_candidates(t_cell *cell, t_cell **grid, int n, int num);
void	place_and_lock(t_cell *cell, t_cell **grid, int num, int n);
void	check_and_update_best_cell(t_cell **grid, int *coords, int **best,
			int n);
void	fill_clues_array(char *arg, int *clues, int gridsize);

// algo.c
int		solve(t_cell **grid, int *clues, int n);
void	lock_cells_from_simple_clues_cols(t_cell **grid, int *clues, int n);
void	lock_cells_from_simple_clues_rows(t_cell **grid, int *clues, int n);
void	lock_cells_from_advanced_clues(t_cell **grid, int *clues, int n);
int		find_best_empty_cell(t_cell **grid, int *row, int *col, int n);

// skyline.c
int		check_top_view(t_cell **grid, int *clues, int n, int i);
int		check_bottom_view(t_cell **grid, int *clues, int n, int i);
int		check_left_view(t_cell **grid, int *clues, int n, int i);
int		check_right_view(t_cell **grid, int *clues, int n, int i);
int		count_visible_buildings(int *line, int n);

#endif