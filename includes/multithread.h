/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelencl <fdelencl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by fdelencl          #+#    #+#             */
/*   Updated: 2016/06/08 20:16:28 by fdelencl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITHREAD_H
# define MULTITHREAD_H

# include <pthread.h>

# define MAX_THREAD 7

typedef struct		s_thread
{
	int				thread_amount;
	int				current_p;
	// pthread_mutex_t	*exposed;
	// pthread_mutex_t	*lock;
}					t_thread;

void				rasterize_mt(t_core *core);
int					rasterize_one(t_core *core);
void				*doctrine(void *core);
t_thread			*get_ts();
pthread_t			*new_thread(void *(*f)(void *), void *arg);

#endif
