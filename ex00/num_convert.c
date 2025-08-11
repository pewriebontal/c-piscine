/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:22:04 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 22:13:04 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//                   _oo0oo_
//                  o8888888o
//                  88" . "88
//                  (| -_- |)
//                  0\  =  /0
//                ___/`---'\___
//              .' \\|     |// '.
//             / \\|||  :  |||// |
//            / _||||| -:- |||||- |
//           |   | \\\  -  /// |   |
//           | \_|  ''\---/''  |_/ |
//           \  .-\__  '-'  ___/-. /
//         ___'. .'  /--.--\  `. .'___
//      ."" '<  `.___\_<|>_/___.' >' "".
//     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//     \  \ `_.   \_ __\ /__ _/   .-` /  /
// =====`-.____`.___ \_____/___.-`___.-'=====
//                   `=---='
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           佛祖保佑         永无BUG

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

void	process_one_group(t_dict_entry *dict, int d_size, char *n_str,
		int *vars)
{
	char	group_buffer[4];
	int		group_idx;
	int		group_count;
	int		first_len;
	int		*space_flag;

	group_idx = vars[0];
	group_count = vars[1];
	first_len = vars[2];
	space_flag = (int *)&(vars[3]);
	get_current_group(group_buffer, n_str, group_idx, first_len);
	if (is_group_non_zero(group_buffer))
	{
		print_three_digits(dict, d_size, group_buffer, space_flag);
		if (group_idx < group_count - 1)
			print_magnitude(dict, d_size, group_count - 1 - group_idx,
				space_flag);
	}
}

void	process_groups(t_dict_entry *dict, int dict_size, char *num_str)
{
	int		vars[4];
	size_t	len;

	len = ft_strlen(num_str);
	vars[0] = 0;
	vars[1] = (len + 2) / 3;
	vars[2] = len % 3;
	if (vars[2] == 0 && len > 0)
		vars[2] = 3;
	vars[3] = 0;
	while (vars[0] < vars[1])
	{
		process_one_group(dict, dict_size, num_str, vars);
		vars[0]++;
	}
}

void	convert_number(t_dict_entry *dict, int d_size, char *num_str)
{
	char	*zero_val;

	if (ft_strlen(num_str) == 1 && num_str[0] == '0')
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
