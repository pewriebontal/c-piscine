/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:20:15 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/05 13:45:27 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (!str && str == NULL)
		return ;
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

// int	main(void)
// {
// 	char	*a;

// 	a = NULL;
// 	ft_putstr(a);
// 	ft_putstr("Hello, World!\n");
// 	return (0);
// }
