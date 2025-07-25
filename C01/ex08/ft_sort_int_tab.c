/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:58:13 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/25 08:30:44 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	int	num[] = {5, 2, 3, 1, 9, 312, 1};
	int	size;
	int	i;
	int	j;

	i = 0;
	size = sizeof(num) / sizeof(num[0]);
	printf("Before sorting: ");
	while (i < size)
	{
		printf("%d ", num[i]);
		i++;
	}
	ft_sort_int_tab(num, size);
	i = 0;
	printf("\n");
	printf("After sorting: ");
	while (i < size)
	{
		printf("%d ", num[i]);
		i++;
	}
	return (0);
}*/
