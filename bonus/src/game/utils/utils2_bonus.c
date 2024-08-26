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

#include "../../../includes/cub3d_bonus.h"

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

void	get_direction2(t_data *data)
{
	if (data->player.direction == W)
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.right_x = 0;
		data->player.right_y = -1;
		data->player.left_x = 0;
		data->player.left_y = 1;
		data->player.plane_x = 0;
		data->player.plane_y = -1;
	}
	else if (data->player.direction == E)
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.right_x = 0;
		data->player.right_y = 1;
		data->player.left_x = 0;
		data->player.left_y = -1;
		data->player.plane_x = 0;
		data->player.plane_y = 1;
	}
}

void	get_direction(t_data *data)
{
	if (data->player.direction == N)
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.right_x = 1;
		data->player.right_y = 0;
		data->player.left_x = -1;
		data->player.left_y = 0;
		data->player.plane_x = 1;
		data->player.plane_y = 0;
	}
	else if (data->player.direction == S)
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.right_x = -1;
		data->player.right_y = 0;
		data->player.left_x = 1;
		data->player.left_y = 0;
		data->player.plane_x = -1;
		data->player.plane_y = 0;
	}
	else
		get_direction2(data);
}
