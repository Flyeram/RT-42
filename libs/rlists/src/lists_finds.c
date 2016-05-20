/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_finds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/27 22:50:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rlists.h>

int	list_index_of(t_list *list, void *data)
{
	int	i;
	t_node *node;

	node = list->start;
	i = 0;
	while (node != NULL)
	{
		if (node->data == data)
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

t_node	*list_node_of(t_list *list, void *data)
{
	t_node *node;

	node = list->start;
	while (node != NULL)
	{
		if (node->data == data)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_node	*list_get_node_at(t_list *list, int index)
{
	t_node *node;

	if (index < 0 || index >= (int)list->count)
		return (NULL);
	if (index < (int)list->count / 2)
	{
		node = list->start;
		while (index-- > 0)
			node = node->next;
		return (node);
	}
	else
	{
		index = list->count - index - 1;
		node = list->end;
		while (index-- > 0)
			node = node->prev;
		return (node);
	}
}

void	*list_get_data_at(t_list *list, int index)
{
	t_node *node;

	if (index < (int)list->count / 2)
	{
		node = list->start;
		while (index-- > 0)
			node = node->next;
		return (node->data);
	}
	else
	{
		index = list->count - index - 1;
		node = list->end;
		while (index-- > 0)
			node = node->prev;
		return (node->data);
	}
}
