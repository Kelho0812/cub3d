/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:05:19 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 16:05:19 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

// uint32_t getTick() {
//     struct timespec ts;
//     unsigned theTick = 0U;
//     clock_gettime( CLOCK_MONOTONIC, &ts );
//     theTick  = ts.tv_nsec / 1000000;
//     theTick += ts.tv_sec * 1000;
//     return theTick;
// }

void    render_player(t_data *data)
{
    int x1;
    int y1;
    int x = data->player.px * MINIMAP_SIZE;
    int y = data->player.py * MINIMAP_SIZE;

    y1 = 0 - PLAYER_SIZE / 2;
    while (y1 < PLAYER_SIZE / 2)
    {
        x1 = 0 - PLAYER_SIZE / 2;
        while (x1 < PLAYER_SIZE / 2)
        {
            data->rays.camera_x = 2 * x1 / (double)WIDTH - 1;
            data->rays.ray_dir_x = data->player.dir_x + data->player.plane_x
                * data->rays.camera_x;
            data->rays.ray_dir_y = data->player.dir_y + data->player.plane_y
                * data->rays.camera_x;
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
			{
                my_pixel_put(x + x1, y + y1, 0xFF0000, data);
			}
            draw_line
            x1++;
        }
        y1++;
    }
}
