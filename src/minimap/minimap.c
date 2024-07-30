/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:03:32 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 13:03:32 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void render_block(int x, int y, int block_size, t_data *data)
{
    int y1;
    int x1;

    y1 = 0;
    while (y1 < block_size - 1)
    {
        x1 = 0;
        while (x1 < block_size - 1)
        {
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
                mlx_pixel_put(data->window.mlx, data->window.mlx_win, x + x1, y + y1, 0xFFFFFF);
            x1++;
        }
        y1++;
    }
}

void    render_player(t_data *data)
{
    int x1;
    int y1;

    y1 = 0;
    while (y1 < 6)
    {
        x1 = 0;
        while (x1 < 6)
        {
            if (data->player.x * 10 + x1 < WIDTH && data->player.y * 10 + y1 < HEIGHT)
                mlx_pixel_put(data->window.mlx, data->window.mlx_win, data->player.x * 10 + x1 + x1, data->player.y * 10 + x1 + y1, 0x222222);
            x1++;
        }
        y1++;
    }
}

void	render_minimap(t_data *data)
{
    int y; 
    int x;
	int block_size = 10;

    y = 0;
    x = 0;
    while (data->map.full_file_array[y])
    {
        x = 0;
        while (data->map.full_file_array[y][x])
        {
            if (data->map.full_file_array[y][x] == '1')
                render_block(x * block_size, y * block_size, block_size, data);
            x++;
        }
        y++;
    }
    render_player(data);
}
