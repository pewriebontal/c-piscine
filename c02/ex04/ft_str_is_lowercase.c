/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:59:52 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 15:59:52 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	int	i;

	char * str;
//	str = "1232";
	str = "Hello1";
//	str = "hello";
	i = ft_str_is_lowercase(str);
	printf("%d", i);
	return (0);
}
*/
