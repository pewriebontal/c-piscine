/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:05:01 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 22:12:56 by mikhaing         ###   ########.fr       */
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

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define GNL_BUFFER_SIZE 42
# define MAX_FD 1024

typedef struct s_dict_entry
{
	char			*key_num;
	char			*value_word;
}					t_dict_entry;

typedef struct s_node
{
	t_dict_entry	*entry;
	struct s_node	*next;
}					t_node;

// dict_parse.c
int					parse_line(char *line, t_dict_entry *entry);
t_dict_entry		*convert_list_to_array(t_node *head, int size);
t_node				*read_to_list(int fd);
t_dict_entry		*load_dictionary(char *path, int *dict_size);

// dict_utils.c
char				*find_value(t_dict_entry *dict, int size, char *key);
void				free_dictionary(t_dict_entry *dict, int size);

// gnl.c
char				*get_next_line(int fd);

// list_utils.c
t_node				*create_node(t_dict_entry entry);
void				add_node_back(t_node **head, t_node *new_node);
int					get_list_size(t_node *head);
void				free_list(t_node *head);

// string_utils1.c
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

// string_utils.c
void				ft_putstr(char *str, int apply_space);
char				*ft_strdup(char *src);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);

// val.c
int					is_valid_number(char *str);
int					is_group_non_zero(char *group);
int					check_dict(t_dict_entry *dict, int size);
void				print_error(char *message);

// num_convert.c
void				get_current_group(char *group_buf, char *num_str, int g_idx,
						int f_len);
void				process_groups(t_dict_entry *dict, int dict_size,
						char *num_str);
void				convert_number(t_dict_entry *dict, int d_size,
						char *num_str);

// convert_utils.c
void				print_tens(t_dict_entry *d, int ds, char *tens_digits,
						int *space_flag);
void				print_three_digits(t_dict_entry *d, int ds, char *grp,
						int *space_flag);
void				print_magnitude(t_dict_entry *d, int ds, int mag_idx,
						int *space_flag);

#endif