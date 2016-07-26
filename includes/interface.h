/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:04:38 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 02:00:10 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# define NATIVE_WIDTH 1280
# define NATIVE_HEIGHT 720

void	interface_init(t_interface *ui, t_vector2f screen_size);
void	interface_poll_events(t_core *core);
void	interface_draw(t_interface *ui, SDL_Surface *s);

#endif
