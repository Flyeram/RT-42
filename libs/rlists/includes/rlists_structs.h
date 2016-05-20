/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlists_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/27 22:50:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RLISTS_STRUCTS_H
# define RLISTS_STRUCTS_H

struct		s_node
{
	void	*data;
	t_node	*next;
	t_node	*prev;
};

struct		s_list
{
	t_node	*start;
	t_node	*end;
	t_node	*iterator;
	size_t	count;
	size_t	elem_size;
	int	current;
};

#endif
