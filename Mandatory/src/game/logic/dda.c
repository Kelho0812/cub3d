/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:31:47 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 12:31:47 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	define_steps(t_dda_values *dda_values, t_data *data);

void	init_values_dda(int x, t_dda_values *dda_values, t_data *data)
{
	dda_values->map_x = (int)data->player.px;
	dda_values->map_y = (int)data->player.py;
	data->rays.camera_x = 2 * x / (double)WIDTH - 1;
	data->rays.ray_dir_x = data->player.dir_x + data->player.plane_x
		* data->rays.camera_x;
	data->rays.ray_dir_y = data->player.dir_y + data->player.plane_y
		* data->rays.camera_x;
}

void	calculate_distances(t_dda_values *dda_values, t_data *data)
{
	if (data->rays.ray_dir_x == 0)
		data->dist.delta_dist_x = 1e30;
	else
		data->dist.delta_dist_x = fabs(1 / data->rays.ray_dir_x);
	if (data->rays.ray_dir_y == 0)
		data->dist.delta_dist_y = 1e30;
	else
		data->dist.delta_dist_y = fabs(1 / data->rays.ray_dir_y);
	define_steps(dda_values, data);
}

void	execute_dda(t_dda_values *dda_values, t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->dist.side_dist_x < data->dist.side_dist_y)
		{
			data->dist.side_dist_x += data->dist.delta_dist_x;
			dda_values->map_x += dda_values->step_x;
			dda_values->side = 0;
		}
		else
		{
			data->dist.side_dist_y += data->dist.delta_dist_y;
			dda_values->map_y += dda_values->step_y;
			dda_values->side = 1;
		}
		if (data->map.full_map_array[dda_values->map_y]
			[dda_values->map_x] == '1')
			hit = 1;
	}
}

void	find_distance_to_wall(t_dda_values *dda_values, t_data *data)
{
	if (dda_values->side == 0)
		data->dist.perp_wall_dist = data->dist.side_dist_x
			- data->dist.delta_dist_x;
	else
		data->dist.perp_wall_dist = data->dist.side_dist_y
			- data->dist.delta_dist_y;
	dda_values->line_height = (int)(HEIGHT / data->dist.perp_wall_dist);
}

static void	define_steps(t_dda_values *dda_values, t_data *data)
{
	if (data->rays.ray_dir_x < 0)
	{
		dda_values->step_x = -1;
		data->dist.side_dist_x = (data->player.px - dda_values->map_x)
			* data->dist.delta_dist_x;
	}
	else
	{
		dda_values->step_x = 1;
		data->dist.side_dist_x = (dda_values->map_x + 1.0 - data->player.px)
			* data->dist.delta_dist_x;
	}
	if (data->rays.ray_dir_y < 0)
	{
		dda_values->step_y = -1;
		data->dist.side_dist_y = (data->player.py - dda_values->map_y)
			* data->dist.delta_dist_y;
	}
	else
	{
		dda_values->step_y = 1;
		data->dist.side_dist_y = (dda_values->map_y + 1.0 - data->player.py)
			* data->dist.delta_dist_y;
	}
}
