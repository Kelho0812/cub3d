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

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		handle_close(data);
	}
    if (keysym == XK_Up)
    {
        if (data->map.full_map_array[(int)(data->player.py + data->player.dirY * data->game.move_speed)][(int)(data->player.px)] != '1')
            data->player.py += data->player.dirY * data->game.move_speed;
        if (data->map.full_map_array[(int)(data->player.py)][(int)(data->player.px + data->player.dirX * data->game.move_speed)] != '1')
            data->player.px += data->player.dirX * data->game.move_speed;
    }
    if (keysym == XK_Down)
    {
        if (data->map.full_map_array[(int)(data->player.py - data->player.dirY * data->game.move_speed)][(int)(data->player.px)] != '1')
            data->player.py -= data->player.dirY * data->game.move_speed;
        if (data->map.full_map_array[(int)(data->player.py)][(int)(data->player.px - data->player.dirX * data->game.move_speed)] != '1')
            data->player.px -= data->player.dirX * data->game.move_speed;
    }
    if (keysym == XK_Left)
    {
        double oldDirX = data->player.dirX;
        data->player.dirX = data->player.dirX * cos(-data->game.rotate_speed) - data->player.dirY * sin(-data->game.rotate_speed);
        data->player.dirY = oldDirX * sin(-data->game.rotate_speed) + data->player.dirY * cos(-data->game.rotate_speed);
        double oldPlaneX = data->player.planeX;
        data->player.planeX = data->player.planeX * cos(-data->game.rotate_speed) - data->player.planeY * sin(-data->game.rotate_speed);
        data->player.planeY = oldPlaneX * sin(-data->game.rotate_speed) + data->player.planeY * cos(-data->game.rotate_speed);
    }
    if (keysym == XK_Right)
    {
        double oldDirX = data->player.dirX;
        data->player.dirX = data->player.dirX * cos(data->game.rotate_speed) - data->player.dirY * sin(data->game.rotate_speed);
        data->player.dirY = oldDirX * sin(data->game.rotate_speed) + data->player.dirY * cos(data->game.rotate_speed);
        double oldPlaneX = data->player.planeX;
        data->player.planeX = data->player.planeX * cos(data->game.rotate_speed) - data->player.planeY * sin(data->game.rotate_speed);
        data->player.planeY = oldPlaneX * sin(data->game.rotate_speed) + data->player.planeY * cos(data->game.rotate_speed);
    }
    render_map(data);
	return (0);
}
