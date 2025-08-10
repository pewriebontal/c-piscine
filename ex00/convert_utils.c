/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:21:27 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 20:09:43 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_tens(t_dict_entry *d, int ds, char *tens_digits, int *space_flag)
{
	char	key[3];

	if (tens_digits[0] == '0' && tens_digits[1] != '0')
	{
		key[0] = tens_digits[1];
		key[1] = '\0';
		ft_putstr(find_value(d, ds, key), *space_flag);
		*space_flag = 1;
	}
	else if (tens_digits[0] == '1')
	{
		key[0] = tens_digits[0];
		key[1] = tens_digits[1];
		key[2] = '\0';
		ft_putstr(find_value(d, ds, key), *space_flag);
		*space_flag = 1;
	}
	else if (tens_digits[0] > '1')
	{
		key[0] = tens_digits[0];
		key[1] = '0';
		key[2] = '\0';
		ft_putstr(find_value(d, ds, key), *space_flag);
		*space_flag = 1;
		if (tens_digits[1] != '0')
			print_tens(d, ds, &tens_digits[1], space_flag);
	}
}

void	print_three_digits(t_dict_entry *d, int ds, char *grp, int *space_flag)
{
	size_t	len;
	char	key[2];

	len = ft_strlen(grp);
	if (len == 3 && grp[0] != '0')
	{
		key[0] = grp[0];
		key[1] = '\0';
		ft_putstr(find_value(d, ds, key), *space_flag);
		*space_flag = 1;
		ft_putstr(find_value(d, ds, "100"), *space_flag);
	}
	if (len >= 2)
		print_tens(d, ds, &grp[len - 2], space_flag);
	else if (len == 1 && grp[0] != '0')
		print_tens(d, ds, grp, space_flag);
}

void	print_magnitude(t_dict_entry *d, int ds, int mag_idx, int *space_flag)
{
	char	*key;
	int		num_zeros;
	int		i;

	if (mag_idx > 0)
	{
		num_zeros = mag_idx * 3;
		key = malloc(num_zeros + 2);
		if (!key)
			return ;
		key[0] = '1';
		i = 1;
		while (i <= num_zeros)
		{
			key[i] = '0';
			i++;
		}
		key[i] = '\0';
		ft_putstr(find_value(d, ds, key), *space_flag);
		*space_flag = 1;
		free(key);
	}
}
