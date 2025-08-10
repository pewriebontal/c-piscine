/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:10:20 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 18:50:55 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_group_non_zero(char *group)
{
	int	i;

	i = 0;
	while (group[i])
	{
		if (group[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_dict(t_dict_entry *dict, int size)
{
	if (!find_value(dict, size, "0"))
		return (0);
	if (!find_value(dict, size, "1"))
		return (0);
	if (!find_value(dict, size, "10"))
		return (0);
	if (!find_value(dict, size, "100"))
		return (0);
	return (1);
}

void	print_error(char *message)
{
	write(2, message, ft_strlen(message));
}
