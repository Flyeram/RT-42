/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/27 22:50:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rlists.h>

t_list	*list_new(size_t elem_size)

{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->start = NULL;
	ret->end = NULL;
	ret->iterator = NULL;
	ret->count = 0;
	ret->current = 0;
	ret->elem_size = elem_size;
	return (ret);
}

t_node	*list_push_back(t_list *list, void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->prev = list->end;
	node->next = NULL;
	if (list->end != NULL)
		list->end->next = node;
	list->end = node;
	list->count++;
	if (list->start == NULL)
	{
		list->start = node;
		list->iterator = node;
	}
	return (node);
}

t_node	*list_push_front(t_list *list, void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = list->start;
	node->prev = NULL;
	if (list->start != NULL)
		list->start->prev = node;
	list->start = node;
	list->count++;
	if (list->end == NULL)
	{
		list->end = node;
		list->iterator = node;
	}
	return (node);
}
