/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:09:10 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 18:56:02 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_to_convert;

	if (argc < 2 || argc > 3)
	{
		print_error("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		dict_path = "numbers.dict";
		number_to_convert = argv[1];
	}
	else
	{
		dict_path = argv[1];
		number_to_convert = argv[2];
	}
	return (0);
}
