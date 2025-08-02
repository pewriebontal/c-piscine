/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:11:03 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/02 17:50:32 by aiyahaya         ###   ########.fr       */
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

char	*create_char_array(int size)
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
	clues = create_char_array(grid);
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

int	main(int argc, char *argv[])
{
	int		size;
	int		grid;
	char	*clues;
	char	*col_clues;
	char	*row_clues;

	if (argc == 2)
	{
		clues = argv[1];
		size = ft_strlen(clues);
		grid = ft_gridsize(size);
		if (grid >= 4)
		{
			printf("Solving %d values in a %dx%d grid.\n", size, grid, grid);
			printf("clues: %s\n", clues);
			col_clues = ft_getarr(clues, 1, grid);
			row_clues = ft_getarr(clues, 0, grid);
			printf("cols:  %s\nrows:  %s\n", col_clues, row_clues);
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
