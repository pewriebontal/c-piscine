/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:11:03 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/03 16:33:10 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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



#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct s_cell
{
	int x;
	int y;
	int height;
	int *candidate;
} t_cell;

t_cell **create_grid(int size);

void print_error(void)
{
	write(1, "Error\n", 6);
}

void toggle_candidates(t_cell *cell, t_cell **grid, int n, int restore)
{
	int i;
	int num;
	int value_to_set;

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

void place_and_lock(t_cell *cell, t_cell **grid, int num, int n)
{
	int k;

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

void lock_cells_from_simple_clues_cols(t_cell **grid, int *clues, int n)
{
	int i;
	int j;

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

void lock_cells_from_simple_clues_rows(t_cell **grid, int *clues, int n)
{
	int i;
	int j;

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

void lock_cells_from_advanced_clues(t_cell **grid, int *clues, int n)
{
	int i;

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

int count_visible_buildings(int *line, int n)
{
	int visible_count;
	int max_height;
	int i;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < n)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int check_top_view(t_cell **grid, int *clues, int n, int i)
{
	int j;
	int *line;
	int result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[j][i].height;
	result = (count_visible_buildings(line, n) == clues[i]);
	free(line);
	return (result);
}

int check_bottom_view(t_cell **grid, int *clues, int n, int i)
{
	int j;
	int *line;
	int result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[n - 1 - j][i].height;
	result = (count_visible_buildings(line, n) == clues[n + i]);
	free(line);
	return (result);
}

int check_left_view(t_cell **grid, int *clues, int n, int i)
{
	int j;
	int *line;
	int result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[i][j].height;
	result = (count_visible_buildings(line, n) == clues[2 * n + i]);
	free(line);
	return (result);
}

int check_right_view(t_cell **grid, int *clues, int n, int i)
{
	int j;
	int *line;
	int result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[i][n - 1 - j].height;
	result = (count_visible_buildings(line, n) == clues[3 * n + i]);
	free(line);
	return (result);
}

int is_solution_valid(t_cell **grid, int *clues, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (!check_top_view(grid, clues, n, i) || !check_bottom_view(grid, clues, n, i) || !check_left_view(grid, clues, n, i) || !check_right_view(grid, clues, n, i))
			return (0);
		i++;
	}
	return (1);
}

void check_and_update_best_cell(t_cell **grid, int *coords, int **best,
								int n)
{
	int cand_count;
	int i;

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

int find_best_empty_cell(t_cell **grid, int *row, int *col, int n)
{
	int r_c[2];
	int min_cand;
	int *best[3];

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

void print_permutation(t_cell **grid, int n)
{
	int row;
	int col;
	char c;

	write(1, "\033[0;32m", 7);
	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (grid[row][col].height == 0)
				c = '.';
			else
				c = grid[row][col].height + '0';
			write(1, &c, 1);
			if (col < n - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	write(1, "-----\n", 6);
	write(1, "\033[0m", 4);
}


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


// ASCII index for digits: 48-57
int ft_strlen(char *c)
{
	int i;
	int count;
	char *result;

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

int ft_gridsize(int x)
{
	int i;
	int y;

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

// function to return col/row arrays
// return col arrays when col = 1
// // return row arrays when col = 0
// char *ft_getarr(char *arr, int col, int grid)
// {
// 	char *clues;
// 	int i;

// 	i = 0;
// 	clues = create_array(grid);
// 	while (i < grid * 2)
// 	{
// 		if (col == 1)
// 			clues[i] = arr[i];
// 		else
// 			clues[i] = arr[(grid * 2) + i];
// 		i++;
// 	}
// 	clues[i] = '\0';
// 	return (clues);
// }

void	ft_print_grid(t_cell **grid, int n)
{
	// ANSI escape sequence for red text
	// char *red_color_code = "\x1b[31m";
	// char *green_color_code = "\033[38;5;84m";
	// ANSI escape sequence to reset color
	// char *reset_color_code = "\x1b[0m";

	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			c = grid[row][col].height + '0';
			write(1, &c, 1);
			if (col < n - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

t_cell **create_grid(int size)
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


// int ft_get_row_sight(grid, row, 1, rr)
// {
// 	int count;
// 	count = 0;

// 	return (c)
// }

// int ft_get_col_sight(grid, col, 0, ct)
// {
// }

// int validate(t_cell **grid, int row, int col, char *clues)
// {
// 	int ct;
// 	int cb;
// 	int rl;
// 	int rr;
// 	int size;
// 	int valid;
// 	int r;
// 	int c;
// 	int height;

// 	valid = 0;
// 	size = ft_strlen(clues);
// 	ct = clues[col] - '0';
// 	cb = clues[col + (size / 4)] - '0';
// 	rl = clues[(size / 2) + row] - '0';
// 	rr = clues[(size / 4 * 3) + row] - '0';

// 	height = grid[row][col].height;
// 	r = 0;
// 	c = 0;
// 	while (r < size)
// 	{
// 		if (r < row)
// 		{
// 			ft_get_row_sight(grid, row, 0, rl); // from left
// 			ft_get_row_sight(grid, row, 1, rr); // from right
// 			ft_get_col_sight(grid, col, 0, ct); // from top
// 			ft_get_col_sight(grid, col, 1, cb); // from bottom
// 			ft_get_sight_from_left(grid, row);
// 			if (grid[r][col])
// 		}
// 		r++;
// 	}

// 	printf("check for grid[%d][%d] = %d, result: %d, "
// 		   "ct: %d, cb: %d, rl: %d, rr: %d\n",
// 		   row, col, cell.height, valid,
// 		   ct, cb, rl, rr);
// 	return (valid);
// }

int	main(int argc, char **argv)
{
	int *clues;
	int gridsize;

	if (argc != 2 || !validate_input_and_get_size(argv[1], &gridsize))
	{
		print_error();
		return (1);
	}
	clues = malloc(sizeof(int) * (gridsize * 4));
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