/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:06:13 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:06:13 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	sign = 1;
	count = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		++str;
	}
	if (count % 2 != 0)
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (sign * (int)result);
}
/*
int	main(void)
{
	char	*str;
	int		i;

	str = "-+++++-+-4277a9";
	i = ft_atoi(str);
	printf("%d", i);
}
*/
