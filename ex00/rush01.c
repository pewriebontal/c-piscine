/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:11:03 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/02 15:41:37 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

// ASCII index for digits: 48-57
int	ft_strlen(char *c)
{
	int	i;
	int	count;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 48 && c[i] <= 57)
			count++;
		i++;
	}
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
char	*ft_getarr(char *arr, char opt, int gridsize);

//
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
