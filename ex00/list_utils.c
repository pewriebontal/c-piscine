/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:37:13 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 20:09:52 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_node	*create_node(t_dict_entry entry)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->entry = malloc(sizeof(t_dict_entry));
	if (!new_node->entry)
	{
		free(new_node);
		return (0);
	}
	new_node->entry->key_num = entry.key_num;
	new_node->entry->value_word = entry.value_word;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int	get_list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->entry->key_num);
		free(temp->entry->value_word);
		free(temp->entry);
		free(temp);
	}
}
