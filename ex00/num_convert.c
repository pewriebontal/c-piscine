/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:22:04 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 20:09:54 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	get_current_group(char *group_buf, char *num_str, int g_idx, int f_len)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	while (i < 4)
		group_buf[i++] = '\0';
	if (g_idx == 0)
	{
		i = 0;
		while (i < f_len)
		{
			group_buf[i] = num_str[i];
			i++;
		}
	}
	else
	{
		start = f_len + (g_idx - 1) * 3;
		i = 0;
		k = 0;
		while (i < 3)
			group_buf[k++] = num_str[start + i++];
	}
}

void	process_groups(t_dict_entry *dict, int dict_size, char *num_str)
{
	int		group_idx;
	int		first_group_len;
	char	group_buffer[4];
	size_t	len;
	int		group_count;
	int		space_flag;

	space_flag = 0;
	len = ft_strlen(num_str);
	group_count = (len + 2) / 3;
	first_group_len = len % 3;
	if (first_group_len == 0 && len > 0)
		first_group_len = 3;
	group_idx = 0;
	while (group_idx < group_count)
	{
		get_current_group(group_buffer, num_str, group_idx, first_group_len);
		if (is_group_non_zero(group_buffer))
		{
			print_three_digits(dict, dict_size, group_buffer, &space_flag);
			if (group_idx < group_count - 1)
				print_magnitude(dict, dict_size, group_count - 1 - group_idx,
					&space_flag);
		}
		group_idx++;
	}
}

void	convert_number(t_dict_entry *dict, int d_size, char *num_str)
{
	size_t	len;
	char	*zero_val;

	len = ft_strlen(num_str);
	if (len == 1 && num_str[0] == '0')
	{
		zero_val = find_value(dict, d_size, "0");
		if (zero_val)
			ft_putstr(zero_val, 0);
	}
	else
	{
		process_groups(dict, d_size, num_str);
	}
	ft_putstr("\n", 0);
}
