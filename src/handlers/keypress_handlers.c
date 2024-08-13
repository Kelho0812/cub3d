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
#include "../../includes/cub3d.h"

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->window.mlx, data->window.mlx_win);
		mlx_destroy_display(data->window.mlx);
        free(data->buffer_background);
		free(data->window.mlx);
		exit(0);
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
    printf("DX: %lf\n DY: %lf\n PLX: %lf\n PLY: %lf\n", data->player.dirX, data->player.dirY, data->player.planeX, data->player.planeY);
    render_map(data);
    render_minimap(data);
    render_player(data);
	return (0);
}


int handle_mouse_move(int x, int y, t_data *data)
{
    if (data->camera.prev_x < x)
    {
        double oldDirX = data->player.dirX;
        data->player.dirX = data->player.dirX * cos(-data->game.rotate_speed) - data->player.dirY * sin(-data->game.rotate_speed);
        data->player.dirY = oldDirX * sin(-data->game.rotate_speed) + data->player.dirY * cos(-data->game.rotate_speed);
        double oldPlaneX = data->player.planeX;
        data->player.planeX = data->player.planeX * cos(-data->game.rotate_speed) - data->player.planeY * sin(-data->game.rotate_speed);
        data->player.planeY = oldPlaneX * sin(-data->game.rotate_speed) + data->player.planeY * cos(-data->game.rotate_speed);
    }
    else if (data->camera.prev_x > x)
    {
        double oldDirX = data->player.dirX;
        data->player.dirX = data->player.dirX * cos(data->game.rotate_speed) - data->player.dirY * sin(data->game.rotate_speed);
        data->player.dirY = oldDirX * sin(data->game.rotate_speed) + data->player.dirY * cos(data->game.rotate_speed);
        double oldPlaneX = data->player.planeX;
        data->player.planeX = data->player.planeX * cos(data->game.rotate_speed) - data->player.planeY * sin(data->game.rotate_speed);
        data->player.planeY = oldPlaneX * sin(data->game.rotate_speed) + data->player.planeY * cos(data->game.rotate_speed);
    }
    data->camera.prev_x = x;
    data->camera.prev_y = y;
    render_map(data);
    render_minimap(data);
    render_player(data);
    return (0);
}

// SUL
// DX: 0.079121
//  DY: 0.996865
//  PX: 0.657931
//  PY: -0.052220

