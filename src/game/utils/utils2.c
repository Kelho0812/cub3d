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
}
