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
            color = *(int *)(data->game.animation.texture.info_texture.data + (data->game.animation.slice.y + y)
				* data->game.animation.texture.info_texture.line_len + (data->game.animation.slice.x + x)
				* (data->game.animation.texture.info_texture.bpp / 8));
            my_pixel_put(x, y, color, head->frame);
            x++;
        }
        y++;
    }
}

void    create_frames(t_data *data)
{
    int frames = 12;
    data->game.animation.frames = calloc(1, sizeof(t_frame));
    t_frame *temp = data->game.animation.frames;
    data->game.animation.texture.texture = mlx_xpm_file_to_image(data->window.mlx, 
        "./textures/animation.xpm", &data->game.animation.texture.width, &data->game.animation.texture.height);
    data->game.animation.texture.info_texture.data = mlx_get_data_addr(data->game.animation.texture.texture,
        &data->game.animation.texture.info_texture.bpp, &data->game.animation.texture.info_texture.line_len, 
        &data->game.animation.texture.info_texture.endian);
    data->game.animation.slice.x = 0;
    data->game.animation.slice.y = 0;
    data->game.animation.slice.width = 384;
    data->game.animation.slice.height = 288;
    while (frames)
    {
        add_frame(temp, data);
        data->game.animation.slice.x += data->game.animation.slice.width;
        if (data->game.animation.slice.x >= 1920)
        {
            data->game.animation.slice.x = 0;
            data->game.animation.slice.y += data->game.animation.slice.height;
        }
        if (frames != 1)
        {
            temp->next = calloc(1, sizeof(t_frame));
            temp = temp->next;
        }
        frames--;
    }
    temp->next = data->game.animation.frames;
}