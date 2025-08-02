/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:03:37 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/02 20:51:54 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*create_int_array(int size)
{
	int	i;
	int	*arr;

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

int	digitizer(char *c)
{
	int		i;
	char	*digits;

	i = 0;
	digits = "0123456789";
	while (i <= 9)
	{
		if (c[0] == digits[i])
		{
			return (i);
		}
		i ++;
	}
	return (-1);
}

int	ft_trianglesum(int size)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += (size - i);
		printf("... %d\n", total);
		i++;
	}
	return (total);
}

int	ft_checks(char *c, int size)
{
	int	i;
	int	temp;
	int	total;
	int	trisum;

	i = 0;
	trisum = ft_trianglesum(size);
	while (c[i])
	{
		temp = digitizer(c[i]);
		if (temp >= 0)
			total += temp;
		i++;
	}
	if (trisum == total)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		grid;
	char	*cols;
	char	*rows;

	i = 0;
	grid = 4;
	if (argc == 3)
	{
		cols = argv[1];
		rows = argv[2];
		printf("%d\n", ft_trianglesum(4));
	}
	return (0);
}
