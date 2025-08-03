/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:17:16 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/03 18:38:58 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// |
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//

#include "rush01.h"

int	check_top_view(t_cell **grid, int *clues, int n, int i)
{
	int	j;
	int	*line;
	int	result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[j][i].height;
	result = (count_visible_buildings(line, n) == clues[i]);
	free(line);
	return (result);
}

int	check_bottom_view(t_cell **grid, int *clues, int n, int i)
{
	int	j;
	int	*line;
	int	result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[n - 1 - j][i].height;
	result = (count_visible_buildings(line, n) == clues[n + i]);
	free(line);
	return (result);
}

int	check_left_view(t_cell **grid, int *clues, int n, int i)
{
	int	j;
	int	*line;
	int	result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[i][j].height;
	result = (count_visible_buildings(line, n) == clues[2 * n + i]);
	free(line);
	return (result);
}

int	check_right_view(t_cell **grid, int *clues, int n, int i)
{
	int	j;
	int	*line;
	int	result;

	line = malloc(sizeof(int) * n);
	if (!line)
		return (0);
	j = -1;
	while (++j < n)
		line[j] = grid[i][n - 1 - j].height;
	result = (count_visible_buildings(line, n) == clues[3 * n + i]);
	free(line);
	return (result);
}

/**
 * @brief This helper function looks down a single street and counts how many
 *        buildings are visible from one end.
 *
 * @param line A list of building heights for one street.
 * @param n The number of buildings on that street.
 * @return The total number of buildings that can be seen.
 */
int	count_visible_buildings(int *line, int n)
{
	int	visible_count;
	int	max_height;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < n)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}
