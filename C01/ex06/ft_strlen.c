/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:46:20 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/05 13:45:35 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *str = "Hello";
// 	printf("%d", ft_strlen(str));
// 	printf("%d", (int)strlen(str));
// }