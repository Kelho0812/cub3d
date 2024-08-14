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
	dda_values->mapX = (int)data->player.px;
	dda_values->mapY = (int)data->player.py;
	data->rays.cameraX = 2 * x / (double)WIDTH - 1;
	data->rays.rayDirX = data->player.dirX + data->player.planeX * data->rays.cameraX;
	data->rays.rayDirY = data->player.dirY + data->player.planeY * data->rays.cameraX;
}

void	calculate_distances(t_dda_values *dda_values, t_data * data)
{
	if (data->rays.rayDirX == 0)
		data->dist.deltaDistX = 1e30;
	else
		data->dist.deltaDistX = fabs(1 / data->rays.rayDirX);
	if (data->rays.rayDirY == 0)
		data->dist.deltaDistY = 1e30;
	else
		data->dist.deltaDistY = fabs(1 / data->rays.rayDirY);
	define_steps(dda_values, data);
}

void	execute_dda(t_dda_values *dda_values, t_data *data)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->dist.sideDistX < data->dist.sideDistY)
		{
			data->dist.sideDistX += data->dist.deltaDistX;
			dda_values->mapX += dda_values->stepX;
			dda_values->side = 0;
		}
		else
		{
			data->dist.sideDistY += data->dist.deltaDistY;
			dda_values->mapY += dda_values->stepY;
			dda_values->side = 1;
		}
		if (data->map.full_map_array[dda_values->mapY][dda_values->mapX] == '1')
			hit = 1;
	}
}

void	find_distance_to_wall(t_dda_values *dda_values, t_data *data)
{
	if (dda_values->side == 0)
		data->dist.perpWallDist = data->dist.sideDistX - data->dist.deltaDistX;
	else
		data->dist.perpWallDist = data->dist.sideDistY - data->dist.deltaDistY;
	dda_values->lineHeight = (int)(HEIGHT / data->dist.perpWallDist);
}

static void	define_steps(t_dda_values *dda_values, t_data *data)
{
	if (data->rays.rayDirX < 0)
	{
		dda_values->stepX = -1;
		data->dist.sideDistX = (data->player.px - dda_values->mapX) * data->dist.deltaDistX;
	}
	else
	{
		dda_values->stepX = 1;
		data->dist.sideDistX = (dda_values->mapX + 1.0 - data->player.px) * data->dist.deltaDistX;
	}
	if (data->rays.rayDirY < 0)
	{
		dda_values->stepY = -1;
		data->dist.sideDistY = (data->player.py - dda_values->mapY) * data->dist.deltaDistY;
	}
	else
	{
		dda_values->stepY = 1;
		data->dist.sideDistY = (dda_values->mapY + 1.0 - data->player.py) * data->dist.deltaDistY;
	}
}
