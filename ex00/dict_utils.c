/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:34:14 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 20:09:48 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*find_value(t_dict_entry *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key_num, key) == 0)
			return (dict[i].value_word);
		i++;
	}
	return (0);
}

void	free_dictionary(t_dict_entry *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key_num);
		free(dict[i].value_word);
		i++;
	}
	free(dict);
}
