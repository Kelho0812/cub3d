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

#include "../../../includes/cub3d.h"

static void render_wall(int x, int y, t_data *data);
static void render_floor(int x, int y, t_data *data);

void	render_minimap(t_data *data)
{
	int	y;
	int	x;

    y = 0;
    x = 0;
    while (data->map.full_map_array[y])
    {
        x = 0;
        while (data->map.full_map_array[y][x])
        {
            if (data->map.full_map_array[y][x] == '1')
                render_wall(x * MINIMAP_SIZE, y * MINIMAP_SIZE, data);
            else
                render_floor(x * MINIMAP_SIZE, y * MINIMAP_SIZE, data);
            x++;
        }
        y++;
    }
}

static void render_wall(int x, int y, t_data *data)
{
	int	y1;
	int	x1;
	int	color;

    y1 = 0;
    while (y1 < MINIMAP_SIZE)
    {
        x1 = 0;
        while (x1 < MINIMAP_SIZE)
        {
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
            {
                color =  *(int *)(data->game.celling_texture.info_texture.data + y1
                    * data->game.celling_texture.info_texture.line_len + x1
                    * (data->game.celling_texture.info_texture.bpp / 8));
                my_pixel_put(x + x1, y + y1, color, data);
            }
            x1++;
        }
        y1++;
    }
}

static void render_floor(int x, int y, t_data *data)
{
    int y1;
    int x1;
    int color;

    y1 = 0;
    while (y1 < MINIMAP_SIZE)
    {
        x1 = 0;
        while (x1 < MINIMAP_SIZE)
        {
            color = *(int *)(data->game.floor_texture.info_texture.data + y1
                * data->game.floor_texture.info_texture.line_len + x1
                * (data->game.floor_texture.info_texture.bpp / 8));
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
            {
                my_pixel_put(x + x1, y + y1, color, data);
            }
            x1++;
        }
        y1++;
    }
}
