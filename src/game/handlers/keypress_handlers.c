/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:33:59 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 15:33:59 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	move_up(t_data *data);
static void	move_down(t_data *data);
static void	move_left(t_data *data);
static void	move_right(t_data *data);

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_close(data);
	if (keysym == XK_Up)
		move_up(data);
	if (keysym == XK_Down)
		move_down(data);
	if (keysym == XK_Left)
		move_left(data);
	if (keysym == XK_Right)
		move_right(data);
	return (0);
}

static void	move_up(t_data *data)
{
	if (data->map.full_map_array[(int)(data->player.py + data->player.dir_y
			* data->game.move_speed)][(int)(data->player.px)] != '1')
		data->player.py += data->player.dir_y * data->game.move_speed;
	if (data->map.full_map_array[(int)(data->player.py)][(int)(data->player.px
			+ data->player.dir_x * data->game.move_speed)] != '1')
		data->player.px += data->player.dir_x * data->game.move_speed;
}

static void	move_down(t_data *data)
{
	if (data->map.full_map_array[(int)(data->player.py - data->player.dir_y
			* data->game.move_speed)][(int)(data->player.px)] != '1')
		data->player.py -= data->player.dir_y * data->game.move_speed;
	if (data->map.full_map_array[(int)(data->player.py)][(int)(data->player.px
			- data->player.dir_x * data->game.move_speed)] != '1')
		data->player.px -= data->player.dir_x * data->game.move_speed;
}

static void	move_left(t_data *data)
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

static void	move_right(t_data *data)
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
