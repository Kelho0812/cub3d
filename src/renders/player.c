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

#include "../../includes/cub3d.h"

void    render_player(t_data *data)
{
    int x1;
    int y1;
    int x = data->player.px;
    int y = data->player.py;

    y1 = 0;
    draw_fov(data);
    while (y1 < PLAYER_SIZE)
    {
        x1 = 0;
        while (x1 < PLAYER_SIZE)
        {
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
                my_pixel_put(x + x1, y + y1, 0xFF0000, data);
            x1++;
        }
        y1++;
    }
    mlx_put_image_to_window(data->window.mlx, data->window.mlx_win, data->map.map_img.mlx_img, 0, 0);
    mlx_destroy_image(data->window.mlx, data->map.map_img.mlx_img);
}


void draw_fov(t_data *data)
{
    float ca;
    int raycasted;
    float center_x = data->player.px + (PLAYER_SIZE / 2);
    float center_y = data->player.py + (PLAYER_SIZE / 2);
    float end_x;
    float end_y;

    raycasted = 0;
    ca = data->player.pa - (DEGRESS * 40);
    while (raycasted < 80)
    {
        ca += DEGRESS;
        if (ca < 0)
			ca += 2 * PI;
		else if (ca > 2 * PI)
			ca -= 2 * PI;
        end_x = center_x + (cos(ca) * 30);
        end_y = center_y + (sin(ca) * 30);
        draw_line(center_x, center_y, end_x, end_y, data);
        raycasted++;
    }
}
