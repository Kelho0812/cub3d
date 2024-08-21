/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:46:27 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 14:46:27 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_game_values(t_data *data)
{
	data->player.px += 0.5;
	data->player.py += 0.5;
	data->game.move_speed = 0.08;
	data->game.rotate_speed = 0.05;
	data->game.mouse_position.prev_x = 0;
	data->game.mouse_position.prev_y = 0;
	data->game.step_height = 0;
	data->game.door_status = 0;
	data->game.time = gettimeofday_ms();
}

void	destroy_images(t_data *data)
{
	if (data->game.wall1.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.wall1.texture);
	if (data->game.wall2.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.wall2.texture);
	if (data->game.wall3.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.wall3.texture);
	if (data->game.wall4.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.wall4.texture);
	if (data->game.wall5.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.wall5.texture);
	if (data->game.celling_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.celling_texture.texture);
	if (data->game.floor_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.floor_texture.texture);
	if (data->game.weapon_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.weapon_texture.texture);
}

void	check_door(t_data *data)
{
	if (data->game.door_status == 1)
	{
		if (data->game.animation.frames->next != NULL)
			data->game.animation.frames = data->game.animation.frames->next;
	}
	else if (data->game.door_status == 2)
	{
		if (data->game.animation.frames->prev != NULL)
			data->game.animation.frames = data->game.animation.frames->prev;
		else
			data->game.door_status = 0;
	}
}

void	render_background(t_data *data)
{
	int	x;
	int	y;
	int	celling;
	int	floor;

	celling = CEILING_COLOR;
	floor = FLOOR_COLOR;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2 + data->game.step_height)
				my_pixel_put(x, y, celling, data->game.map_img);
			else
				my_pixel_put(x, y, floor, data->game.map_img);
			x++;
		}
		y++;
	}
}
