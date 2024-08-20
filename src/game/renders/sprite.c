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
    int     frames;
    t_frame *temp;
    t_frame *tail;
    char    *str;
    char    *str2;
    char    *num;

    data->game.animation.frames = calloc(1, sizeof(t_frame));
    temp = data->game.animation.frames;
    temp->prev = NULL;
    frames = 1;
    while (frames < 39)
    {
        num = ft_itoa(frames);
        str = ft_strjoin("./textures/animation", num);
        str2 = ft_strjoin(str, ".xpm");
        free(str);
        temp->texture.texture = mlx_xpm_file_to_image(data->window.mlx, 
        str2, &temp->texture.width, &temp->texture.height);
        temp->texture.info_texture.data = mlx_get_data_addr(temp->texture.texture,
        &temp->texture.info_texture.bpp, &temp->texture.info_texture.line_len, 
        &temp->texture.info_texture.endian);
        if (frames + 1 != 39)
        {
            temp->next = calloc(1, sizeof(t_frame));
            tail = temp;
            temp = temp->next;
        }
        if (frames != 1)
        {
            temp->prev = tail;
        }
        frames++;
    }
    temp->next = NULL;
}