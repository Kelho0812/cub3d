/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:06:35 by jorteixe          #+#    #+#             */
/*   Updated: 2024/08/21 10:06:35 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move_left(t_data *data)
{
	data->player.px -= data->player.dir_x * data->game.move_speed;
}

void	move_right(t_data *data)
{
	data->player.px += data->player.dir_x * data->game.move_speed;
}

void	turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-data->game.rotate_speed)
		- data->player.dir_y * sin(-data->game.rotate_speed);
	data->player.dir_y = old_dir_x * sin(-data->game.rotate_speed)
		+ data->player.dir_y * cos(-data->game.rotate_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-data->game.rotate_speed)
		- data->player.plane_y * sin(-data->game.rotate_speed);
	data->player.plane_y = old_plane_x * sin(-data->game.rotate_speed)
		+ data->player.plane_y * cos(-data->game.rotate_speed);
}

void	turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(data->game.rotate_speed)
		- data->player.dir_y * sin(data->game.rotate_speed);
	data->player.dir_y = old_dir_x * sin(data->game.rotate_speed)
		+ data->player.dir_y * cos(data->game.rotate_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(data->game.rotate_speed)
		- data->player.plane_y * sin(data->game.rotate_speed);
	data->player.plane_y = old_plane_x * sin(data->game.rotate_speed)
		+ data->player.plane_y * cos(data->game.rotate_speed);
}
