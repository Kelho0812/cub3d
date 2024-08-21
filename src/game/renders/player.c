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

#include "../../../includes/cub3d.h"

static void	draw_fov(t_data *data, int x, int y);

void	render_player(t_data *data)
{
	int		x1;
	int		y1;
	int		x;
	int		y;

	x = data->player.px * MINIMAP_SIZE;
	y = data->player.py * MINIMAP_SIZE;
	draw_fov(data, x, y);
	y1 = 0 - PLAYER_SIZE / 2;
	while (y1 < PLAYER_SIZE / 2)
	{
		x1 = 0 - PLAYER_SIZE / 2;
		while (x1 < PLAYER_SIZE / 2)
		{
			if (x + x1 < WIDTH && y + y1 < HEIGHT)
			{
				my_pixel_put(x + x1, y + y1, 0xFF0000, data->game.map_img);
			}
			x1++;
		}
		y1++;
	}
}

static void	draw_fov(t_data *data, int x, int y)
{
	float	x_step;

	x_step = -0.8;
	while (x_step < 0.8)
	{
		data->rays.ray_dir_x = data->player.dir_x + data->player.plane_x
			* x_step;
		data->rays.ray_dir_y = data->player.dir_y + data->player.plane_y
			* x_step;
		draw_line(x, y, x + (15 * data->rays.ray_dir_x), y + (15
				* data->rays.ray_dir_y), data);
		x_step += 0.08;
	}
}
