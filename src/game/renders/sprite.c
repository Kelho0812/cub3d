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

// void    add_frame(t_frame *head, t_data *data, t_texture *ptr)
// {
//     int x;
//     int y;
//     int color;

//     y = 0;
//     head->frame.mlx_img = mlx_new_image(data->window.mlx, ptr->width, ptr->height);
//     head->frame.data = mlx_get_data_addr(head->frame.mlx_img, &head->frame.bpp, &head->frame.line_len, &head->frame.endian);
//     while (y < ptr->height)
//     {
//         x = 0;
//         while (x < ptr->width)
//         {
//             color = *(int *)(ptr->info_texture.data + y
// 				* ptr->info_texture.line_len + x
// 				* (ptr->info_texture.bpp / 8));
//             my_pixel_put(x, y, color, head->frame);
//             x++;
//         }
//         y++;
//     }
// }

void    create_frames(t_data *data)
{
    int frames = 3;
    t_frame *temp;
    t_texture tex1;
    t_texture tex2;
    t_texture tex3;

    data->game.animation.frames = calloc(1, sizeof(t_frame));
    temp = data->game.animation.frames;
    tex1.texture = mlx_xpm_file_to_image(data->window.mlx, 
        "./textures/fire1.xpm", &tex1.width, &tex1.height);
    tex1.info_texture.data = mlx_get_data_addr(tex1.texture,
        &tex1.info_texture.bpp, &tex1.info_texture.line_len, 
        &tex1.info_texture.endian);
    tex2.texture = mlx_xpm_file_to_image(data->window.mlx, 
        "./textures/fire2.xpm", &tex2.width, &tex2.height);
    tex2.info_texture.data = mlx_get_data_addr(tex2.texture,
        &tex2.info_texture.bpp, &tex2.info_texture.line_len, 
        &tex2.info_texture.endian);
    tex3.texture = mlx_xpm_file_to_image(data->window.mlx, 
        "./textures/fire3.xpm", &tex3.width, &tex3.height);
    tex3.info_texture.data = mlx_get_data_addr(tex3.texture,
        &tex3.info_texture.bpp, &tex3.info_texture.line_len, 
        &tex3.info_texture.endian);
    while (frames)
    {
        if (frames == 3)
            temp->texture = tex1;
        else if (frames == 2)
            temp->texture = tex2;
        else if (frames == 1)
            temp->texture = tex3;
        if (frames != 1)
        {
            temp->next = calloc(1, sizeof(t_frame));
            temp = temp->next;
        }
        frames--;
    }
    temp->next = data->game.animation.frames;
}