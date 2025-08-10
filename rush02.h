/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:05:01 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 18:36:15 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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

void				ft_putstr(char *str, int apply_space);
char				*ft_strdup(char *src);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

// list_utils.c
t_node				*create_node(t_dict_entry entry);
void				add_node_back(t_node **head, t_node *new_node);
int					get_list_size(t_node *head);
void				free_list(t_node *head);

// dict_paras.c
int					parse_line(char *line, t_dict_entry *entry);
t_dict_entry		*convert_list_to_array(t_node *head, int size);

// dict_utils.c
char				*find_value(t_dict_entry *dict, int size, char *key);
void				free_dictionary(t_dict_entry *dict, int size);

// gnl.c
char				*get_next_line(int fd);

#endif