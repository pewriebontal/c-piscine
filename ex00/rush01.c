/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchoo <zchoo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:11:03 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/02 22:05:58 by zchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//use stdlib.h for malloc & free

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

typedef struct s_cell
{
	// int *clue;
	int height;
	int *candidate;
} t_cell;

char	*create_array(int size)
{
	char	*arr;
	int		i;

	arr = malloc(size * sizeof(int));
	i = 0;
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = i * 2;
		i++;
	}
	return (arr);
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
		i --;
	}
	return (y);
}

// function to return col/row arrays
// return col arrays when col = 1
// return row arrays when col = 0
char	*ft_getarr(char *arr, int col, int grid)
{
	char	*clues;
	int		i;

	i = 0;
	clues = create_array(grid);
	while (i < grid * 2)
	{
		if (col == 1)
			clues[i] = arr[i];
		else
			clues[i] = arr[(grid * 2) + i];
		i++;
	}
	clues[i] = '\0';
	return (clues);
}

void ft_print_grid(t_cell *grid[], int rows, int cols)
{
	    // ANSI escape sequence for red text
		// char *red_color_code = "\x1b[31m"; 
		//char *green_color_code = "\033[38;5;84m";
		// ANSI escape sequence to reset color
		// char *reset_color_code = "\x1b[0m"; 

	int		r;
	int		c;
	char	num;

	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < cols)
		{
			if (grid[r][c].height)
				num = grid[r][c].height + '0';
			else
				num = ' ';

			// Write the red color code
			// if ((r == 0 || r == rows - 1) || (c == 0 || c == cols - 1))
			// 	write(1, red_color_code, ft_strlen(red_color_code));
			write(1, &num, 1);
			// Write the reset color code
			// if ((r == 0 || r == rows - 1) || (c == 0 || c == cols - 1))
			// 	write(1, reset_color_code, ft_strlen(reset_color_code));

			if (c < cols -1)
				write(1, ", ", 2);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

t_cell **create_grid(int size)
{
	int c;
	int r;
	int i = 0;
	t_cell **grid;
	t_cell *temp;
	// 1. Allocate memory for row pointers
	grid = malloc(size * sizeof(t_cell *));
	if (grid == NULL) {
		// Handle allocation failure
		//return 1;
	}

	// 2. Allocate memory for each row
	while (i < size)
	{
		grid[i] = malloc(size * sizeof(t_cell));
		if (grid[i] == NULL) {
			// Handle allocation failure
			//return 1;
		}
		i++;
	}

	r = 0;
	c = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			//grid[r][c].height = c + 1;
			temp = &grid[r][c];
			temp->height = c + 1;
			temp->candidate = malloc(size * sizeof(int));
			c++;
		}
		r++;
	}

	//grid[0][0].candidate[0] = 123;

	return grid;
}

int ft_get_row_sight(grid, row, 1, rr)
{
	int count;
	count = 0;

	return (c)
}

int ft_get_col_sight(grid, col, 0, ct)
{

}

int validate(t_cell **grid, int row, int col, char *clues)
{
	int	ct;
	int	cb;
	int	rl;
	int	rr;
	int	size;
	int valid;
	int	r;
	int	c;
	int height;

	valid = 0;
	size = ft_strlen(clues);
	ct = clues[col] - '0';
	cb = clues[col + (size / 4)] - '0';
	rl = clues[(size / 2) + row] - '0';
	rr = clues[(size / 4 * 3) + row] - '0';

	height = grid[row][col].height;
	r = 0;
	c = 0;
	while (r < size)
	{
		if (r < row)
		{
			ft_get_row_sight(grid, row, 0, rl); // from left
			ft_get_row_sight(grid, row, 1, rr); // from right
			ft_get_col_sight(grid, col, 0, ct); // from top
			ft_get_col_sight(grid, col, 1, cb); // from bottom
			ft_get_sight_from_left(grid, row);
			if (grid[r][col])
		}
		r++;
	}

	printf("check for grid[%d][%d] = %d, result: %d, "
			"ct: %d, cb: %d, rl: %d, rr: %d\n",
			row, col, cell.height, valid,
			ct, cb, rl, rr);
	return (valid);
}

int	main(int argc, char *argv[])
{
	int		size;
	int		gridsize;
	char	*clues;
	char	*col_clues;
	char	*row_clues;
	//int		*clues;

	t_cell	**grid;

	if (argc == 2)
	{
		clues = argv[1];
		size = ft_strlen(clues);
		gridsize = ft_gridsize(size);
		if (gridsize >= 4)
		{
			printf("Solving %d values in a %dx%d grid.\n", size, gridsize, gridsize);
			printf("clues: %s\n", clues);
			col_clues = ft_getarr(clues, 1, gridsize);
			row_clues = ft_getarr(clues, 0, gridsize);
			printf("cols:  %s\nrows:  %s\n", col_clues, row_clues);



			grid = create_grid(gridsize);
			ft_print_grid(grid, gridsize, gridsize);
			//printf("%d", grid[0][0].candidate[0]);
			validate(grid, 0, 1, clues);


			free(col_clues);
			free(row_clues);
		}
		else
		{
			write(1, "Error\n", 6);
			return (1);
		}
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
