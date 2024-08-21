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

// void	door_case(t_data *data, t_dda_values dda_values, t_rec_val *temp, int *hit)
// {
	
// }

void	execute_dda(t_dda_values *dda_values, t_data *data, int x)
{
	int	hit;
	t_rec_val	temp;

	hit = 0;
	while (hit == 0)
	{
		if (data->dist.side_dist_x < data->dist.side_dist_y)
		{
			data->dist.side_dist_x += data->dist.delta_dist_x;
			dda_values->map_x += dda_values->step_x;
			temp.side = 0;
		}
		else
		{
			data->dist.side_dist_y += data->dist.delta_dist_y;
			dda_values->map_y += dda_values->step_y;
			temp.side = 1;
		}
		if (!ft_strchr("0NWES6", data->map.full_map_array[dda_values->map_y]
			[dda_values->map_x]))
		{
			temp.map_x = dda_values->map_x;
			temp.map_y = dda_values->map_y;
			find_distance_to_wall(data, &temp);
			hit = 1;
		}
		else if (ft_strchr("6", data->map.full_map_array[dda_values->map_y]
			[dda_values->map_x]))
		{
			temp.map_x = dda_values->map_x;
			temp.map_y = dda_values->map_y;
			find_distance_to_wall(data, &temp);
			execute_dda(dda_values, data, x);
			hit = 1;
		}
	}
	draw_stripe(x, data, &temp);
}

void	find_distance_to_wall(t_data *data, t_rec_val *temp)
{
	if (temp->side == 0)
		temp->wallDist = data->dist.side_dist_x
			- data->dist.delta_dist_x;
	else
		temp->wallDist = data->dist.side_dist_y
			- data->dist.delta_dist_y;
	temp->line_height = (int)(HEIGHT / temp->wallDist);
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
