/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:09:10 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 22:13:02 by mikhaing         ###   ########.fr       */
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

void	run_conversion(char *dict_path, char *number_to_convert)
{
	t_dict_entry	*dictionary;
	int				dict_size;

	if (!is_valid_number(number_to_convert))
	{
		print_error("Error\n");
		return ;
	}
	dictionary = load_dictionary(dict_path, &dict_size);
	if (!dictionary || !check_dict(dictionary, dict_size))
	{
		print_error("Dict Error\n");
		if (dictionary)
			free_dictionary(dictionary, dict_size);
		return ;
	}
	convert_number(dictionary, dict_size, number_to_convert);
	free_dictionary(dictionary, dict_size);
}

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
	run_conversion(dict_path, number_to_convert);
	return (0);
}
