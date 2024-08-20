/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:30:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/17 12:30:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void    add_frame(t_frame *head, t_data *data)
{
    int x;
    int y;
    int color;

    y = 0;
    head->frame.mlx_img = mlx_new_image(data->window.mlx, data->game.animation.slice.width, data->game.animation.slice.height);
    head->frame.data = mlx_get_data_addr(head->frame.mlx_img, &head->frame.bpp, &head->frame.line_len, &head->frame.endian);
    while (y < data->game.animation.slice.height)
    {
        x = 0;
        while (x < data->game.animation.slice.width)
        {

            my_pixel_put(x, y, color, head->frame);
            x++;
        }
        y++;
    }
}

void    create_frames(t_data *data)
{
    int frames = 12;
    data->game.animation.frames = NULL;
    data->game.animation.slice.x = 0;
    data->game.animation.slice.y = 0;
    data->game.animation.slice.width = 384;
    data->game.animation.slice.height = 288;
    while (frames)
    {
        add_frame(data->game.animation.frames, data);
        data->game.animation.slice.x += data->game.animation.slice.width;
        if (data->game.animation.slice.x >= 1920)
        {
            data->game.animation.slice.x = 0;
            data->game.animation.slice.y += data->game.animation.slice.height;
        }
        frames--;
    }
}