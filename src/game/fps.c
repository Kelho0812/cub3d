/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:20:25 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/15 11:20:25 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static uint64_t	gettimeofday_ms(void) {
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    update_time(t_data * data)
{
    char *frame_time;

    data->game.old_time = data->game.time;
    data->game.time = gettimeofday_ms();
    data->game.frame_time = (data->game.time - data->game.old_time) / 1000.0;
    frame_time = ft_itoa((int)(1.0/ data->game.frame_time));
    mlx_string_put(data->window.mlx, data->window.mlx_win, WIDTH - 50, 10, 0xFFFFFF, frame_time);
    data->game.move_speed = data->game.frame_time * 1.5;
    data->game.rotate_speed = data->game.frame_time * 0.3;
	free(frame_time);
}
