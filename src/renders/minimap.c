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

void	render_block(int x, int y, t_data *data)
{
	int	y1;
	int	x1;
	int	color;

	y1 = 0;
	while (y1 < data->minimap.height)
	{
		x1 = 0;
		while (x1 < data->minimap.width)
		{
			if (x + x1 < WIDTH && y + y1 < HEIGHT)
			{
				color = *(int *)(data->minimap.texture.data + y1
						* data->minimap.texture.line_len + x1
						* (data->minimap.texture.bpp / 8));
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
	data->map.map_img.mlx_img = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->map.map_img.data = mlx_get_data_addr(data->map.map_img.mlx_img,
			&data->map.map_img.bpp, &data->map.map_img.line_len,
			&data->map.map_img.endian);
	while (data->map.full_map_array[y])
	{
		x = 0;
		while (data->map.full_map_array[y][x])
		{
			if (data->map.full_map_array[y][x] == '1')
				render_block(x * BLOCK_SIZE, y * BLOCK_SIZE, data);
			x++;
			data->map.width = x;
		}
		y++;
	}
	data->map.height = y - 1;
	// printf("%d\n", data->map.width);
	// printf("%d\n", data->map.height);
}
