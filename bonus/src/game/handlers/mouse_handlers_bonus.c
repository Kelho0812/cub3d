/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:33:41 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/15 11:33:41 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	handle_mouse(int x, int y, t_data *data)
{
	if (y < 20)
		mlx_mouse_move(data->window.mlx, data->window.mlx_win, x, HEIGHT - 100);
	if (y > HEIGHT - 99)
		mlx_mouse_move(data->window.mlx, data->window.mlx_win, x, 21);
	if (x < 30)
		mlx_mouse_move(data->window.mlx, data->window.mlx_win, WIDTH - 33, y);
	if (x > WIDTH - 30)
		mlx_mouse_move(data->window.mlx, data->window.mlx_win, 33, y);
	if (y > data->game.mouse_position.prev_y)
	{
		if (data->game.step_height > -100)
			data->game.step_height -= 1;
	}
	else if (y < data->game.mouse_position.prev_y)
	{
		if (data->game.step_height < 100)
			data->game.step_height += 1;
	}
	if (x > data->game.mouse_position.prev_x)
		turn_right(data);
	else if (x < data->game.mouse_position.prev_x)
		turn_left(data);
	data->game.mouse_position.prev_x = x;
	data->game.mouse_position.prev_y = y;
	return (0);
}
