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

void	my_pixel_put(int x, int y, int color, t_data *data)
{
	char	*ptr;

	ptr = NULL;
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		ptr = data->map.map_img.data + (x * (data->map.map_img.bpp / 8)) + (y
				* data->map.map_img.line_len);
		*(unsigned int *)ptr = color;
	}
}

void render_wall(int x, int y, t_data *data)
{
	int	y1;
	int	x1;
	int	color;

    y1 = 0;
    while (y1 < 12)
    {
        x1 = 0;
        while (x1 < 12)
        {
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
            {
                color = *(int *)(data->minimap.minimap_wall.info_texture.data + y1 \
                    * data->minimap.minimap_wall.info_texture.line_len + x1 * (data->minimap.minimap_wall.info_texture.bpp / 8));
                my_pixel_put(x + x1, y + y1, color, data);
            }
            x1++;
        }
        y1++;
    }
}

void render_floor(int x, int y, t_data *data)
{
    int y1;
    int x1;

    y1 = 0;
    while (y1 < 12)
    {
        x1 = 0;
        while (x1 < 12)
        {
            int color =  data->map.floor_color.R << 16 | data->map.floor_color.G << 8 | data->map.floor_color.B;
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
            {
                my_pixel_put(x + x1, y + y1, color, data);
            }
            x1++;
        }
        y1++;
    }
}

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
