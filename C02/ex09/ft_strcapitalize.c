/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:00:30 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/25 08:30:44 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;
	int	cap;

	i = 0;
	cap = 1;
	while (str[i] != '\0')
	{
		j = str[i];
		if (cap == 1 && j >= 'a' && j <= 'z')
			str[i] -= 32;
		else if (cap == 0 && j >= 'A' && j <= 'Z')
			str[i] += 32;
		if (j < '0' || (j > '9' && j < 'A') || (j > 'Z' && j < 'a') || j > 'z')
			cap = 1;
		else
			cap = 0;
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	test1[] = "hello World! i am goinG to conquire Th!@ woRld!";

	ft_strcapitalize(test1);
	printf("Testing: %s\n", test1);
	return (0);
}*/
