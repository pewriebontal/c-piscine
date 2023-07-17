/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:58:03 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 15:58:03 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start ++;
		end --;
	}
}

/*
int	main(void)
{
	int	num[] = {1, 2, 3, 4, 9, 8, 7};
	int	size;
	int	i;
	int	j;

	size = sizeof(num) / sizeof(num[0]);
	i = 0;
	printf("Before: \n");
	while (i < size)
	{
		printf("%d ", num[i]);
		i++;
	}
	ft_rev_int_tab(num, size);
	j = 0;
	printf("\n");
	printf("After: \n");
	while (j < size)
	{
		printf("%d ", num[j]);
		j++;
	}
	return (0);
}
*/
