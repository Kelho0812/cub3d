/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:17:06 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/26 14:17:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move_left(t_data *data)
{
	if (data->map.full_map_array[(int)(data->player.py
			+ data->player.left_y
			* data->game.move_speed)][(int)(data->player.px)] != '1')
		data->player.py += data->player.left_y * data->game.move_speed;
	if (data->map.full_map_array[(int)(data->player.py)]
		[(int)(data->player.px
			+ data->player.left_x * data->game.move_speed)] != '1')
		data->player.px += data->player.left_x * data->game.move_speed;
}

void	move_right(t_data *data)
{
	if (data->map.full_map_array[(int)(data->player.py
			+ data->player.right_y
			* data->game.move_speed)][(int)(data->player.px)] != '1')
		data->player.py += data->player.right_y * data->game.move_speed;
	if (data->map.full_map_array[(int)(data->player.py)]
		[(int)(data->player.px
			+ data->player.right_x * data->game.move_speed)] != '1')
		data->player.px += data->player.right_x * data->game.move_speed;
}
