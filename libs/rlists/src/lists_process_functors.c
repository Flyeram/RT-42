/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_process_functors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/27 22:50:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rlists.h>

void	list_process_range_inner(t_list *list,
				int start,
				int end,
				void (*f)(void *))
{
	t_node *start_node;
	t_node *end_node;
	t_node *iterator;

	start_node = list_get_node_at(list, start);
	end_node = list_get_node_at(list, end);
	iterator = start_node;
	while (iterator != end_node)
	{
		f(iterator->data);
		iterator = iterator->next;
	}
}

void	list_process_at_inner(t_list *list, int index, void (*f)(void *))
{
	f(list_get_node_at(list, index)->data);
}

void	list_process_inner(t_list *list, void (*f)(void *))
{
	t_node *iterator;

	iterator = list->start;
	while (iterator != NULL)
	{
		f(iterator->data);
		iterator = iterator->next;
	}
}
