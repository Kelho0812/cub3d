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

static void	render_wall(int x, int y, t_data *data);
static void	render_minimap_floor(int x, int y, t_data *data);

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
			if (ft_strchr("12345", data->map.full_map_array[y][x]))
				render_wall(x * MINIMAP_SIZE, y * MINIMAP_SIZE, data);
			else if (ft_strchr("06NESW", data->map.full_map_array[y][x]))
				render_minimap_floor(x * MINIMAP_SIZE,
					y * MINIMAP_SIZE, data);
			x++;
		}
		y++;
	}
}

static void	render_wall(int x, int y, t_data *data)
{
	int	y1;
	int	x1;

	y1 = 0;
	while (y1 < MINIMAP_SIZE - 1)
	{
		x1 = 0;
		while (x1 < MINIMAP_SIZE - 1)
		{
			if (x + x1 < WIDTH && y + y1 < HEIGHT)
			{
				my_pixel_put(x + x1, y + y1,
					MINIMAP_WALL_COLOR, data->game.map_img);
			}
			x1++;
		}
		y1++;
	}
}

static void	render_minimap_floor(int x, int y, t_data *data)
{
	int	y1;
	int	x1;

	y1 = 0;
	while (y1 < MINIMAP_SIZE - 1)
	{
		x1 = 0;
		while (x1 < MINIMAP_SIZE - 1)
		{
			if (x + x1 < WIDTH && y + y1 < HEIGHT)
			{
				my_pixel_put(x + x1, y + y1,
					MINIMAP_FLOOR_COLOR, data->game.map_img);
			}
			x1++;
		}
		y1++;
	}
}
