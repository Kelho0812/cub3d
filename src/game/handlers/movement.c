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
	if (ft_strchr("0NWES", data->map.full_map_array[(int)(data->player.py
				+ data->player.left_y
				* data->game.move_speed)][(int)(data->player.px)])
		|| (ft_strchr("6", data->map.full_map_array[(int)(data->player.py
					+ data->player.left_y
					* data->game.move_speed)][(int)(data->player.px)])
			&& data->game.door_status == 1))
		data->player.py += data->player.left_y * data->game.move_speed;
	if (ft_strchr("0NWES",
			data->map.full_map_array[(int)(data->player.py)]
		[(int)(data->player.px
			+ data->player.left_x * data->game.move_speed)])
		|| (ft_strchr("0NWES",
				data->map.full_map_array[(int)(data->player.py)]
				[(int)(data->player.px
					+ data->player.left_x * data->game.move_speed)])
			&& data->game.door_status == 1))
		data->player.px += data->player.left_x * data->game.move_speed;
}

void	move_right(t_data *data)
{
	if (ft_strchr("0NWES", data->map.full_map_array[(int)(data->player.py
				+ data->player.right_y
				* data->game.move_speed)][(int)(data->player.px)])
		|| (ft_strchr("6", data->map.full_map_array[(int)(data->player.py
					+ data->player.right_y
					* data->game.move_speed)][(int)(data->player.px)])
			&& data->game.door_status == 1))
		data->player.py += data->player.right_y * data->game.move_speed;
	if (ft_strchr("0NWES",
			data->map.full_map_array[(int)(data->player.py)]
		[(int)(data->player.px
			+ data->player.right_x * data->game.move_speed)])
		|| (ft_strchr("0NWES",
				data->map.full_map_array[(int)(data->player.py)]
				[(int)(data->player.px
					+ data->player.right_x * data->game.move_speed)])
			&& data->game.door_status == 1))
		data->player.px += data->player.right_x * data->game.move_speed;
}

void	turn_left(t_data *data)
{
	double	temp;
	double	old_plane_x;

	temp = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-data->game.rotate_speed)
		- data->player.dir_y * sin(-data->game.rotate_speed);
	data->player.dir_y = temp * sin(-data->game.rotate_speed)
		+ data->player.dir_y * cos(-data->game.rotate_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-data->game.rotate_speed)
		- data->player.plane_y * sin(-data->game.rotate_speed);
	data->player.plane_y = old_plane_x * sin(-data->game.rotate_speed)
		+ data->player.plane_y * cos(-data->game.rotate_speed);

	//
	temp = data->player.left_x;
	data->player.left_x = data->player.left_x * cos(-data->game.rotate_speed)
		- data->player.left_y * sin(-data->game.rotate_speed);
	data->player.left_y = temp * sin(-data->game.rotate_speed)
		+ data->player.left_y * cos(-data->game.rotate_speed);

	temp = data->player.right_x;
	data->player.right_x = data->player.right_x * cos(-data->game.rotate_speed)
		- data->player.right_y * sin(-data->game.rotate_speed);
	data->player.right_y = temp * sin(-data->game.rotate_speed)
		+ data->player.right_y * cos(-data->game.rotate_speed);
	//
}

void	turn_right(t_data *data)
{
	double	temp;
	double	old_plane_x;

	temp = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(data->game.rotate_speed)
		- data->player.dir_y * sin(data->game.rotate_speed);
	data->player.dir_y = temp * sin(data->game.rotate_speed)
		+ data->player.dir_y * cos(data->game.rotate_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(data->game.rotate_speed)
		- data->player.plane_y * sin(data->game.rotate_speed);
	data->player.plane_y = old_plane_x * sin(data->game.rotate_speed)
		+ data->player.plane_y * cos(data->game.rotate_speed);

	//
	temp = data->player.left_x;
	data->player.left_x = data->player.left_x * cos(data->game.rotate_speed)
		- data->player.left_y * sin(data->game.rotate_speed);
	data->player.left_y = temp * sin(data->game.rotate_speed)
		+ data->player.left_y * cos(data->game.rotate_speed);

	temp = data->player.right_x;
	data->player.right_x = data->player.right_x * cos(data->game.rotate_speed)
		- data->player.right_y * sin(data->game.rotate_speed);
	data->player.right_y = temp * sin(data->game.rotate_speed)
		+ data->player.right_y * cos(data->game.rotate_speed);
	//
}
