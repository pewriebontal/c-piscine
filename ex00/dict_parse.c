/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:34:08 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 19:13:32 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_line(char *line, t_dict_entry *entry)
{
	int		i;
	int		j;
	char	key[32];
	char	val[128];

	i = 0;
	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		key[j++] = line[i++];
	key[j] = '\0';
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == ':'))
		i++;
	j = 0;
	while (line[i] && line[i] != '\n')
		val[j++] = line[i++];
	val[j] = '\0';
	if (ft_strlen(key) == 0)
		return (0);
	entry->key_num = ft_strdup(key);
	entry->value_word = ft_strdup(val);
	return (1);
}

t_dict_entry	*convert_list_to_array(t_node *head, int size)
{
	t_dict_entry	*array;
	t_node			*current;
	int				i;

	array = malloc(sizeof(t_dict_entry) * size);
	if (!array)
		return (0);
	current = head;
	i = 0;
	while (current)
	{
		array[i].key_num = ft_strdup(current->entry->key_num);
		array[i].value_word = ft_strdup(current->entry->value_word);
		current = current->next;
		i++;
	}
	return (array);
}

t_node	*read_to_list(int fd)
{
	char			*line;
	t_node			*head;
	t_dict_entry	current_entry;

	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, &current_entry))
			add_node_back(&head, create_node(current_entry));
		else
		{
			free(current_entry.key_num);
			free(current_entry.value_word);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}

t_dict_entry	*load_dictionary(char *path, int *dict_size)
{
	int				fd;
	t_node			*head;
	t_dict_entry	*dictionary;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	head = read_to_list(fd);
	close(fd);
	if (!head)
		return (0);
	*dict_size = get_list_size(head);
	dictionary = convert_list_to_array(head, *dict_size);
	free_list(head);
	if (!dictionary)
		return (0);
	return (dictionary);
}
