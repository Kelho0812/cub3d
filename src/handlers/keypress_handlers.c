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
		free(data->window.mlx);
		exit(0);
	}
    if (keysym == XK_Up)
    {
        data->player.px += data->player.pdx;
        data->player.py += data->player.pdy;
    }
    if (keysym == XK_Down)
     {
        data->player.px -= data->player.pdx;
        data->player.py -= data->player.pdy;
    }
    if (keysym == XK_Left)
    {
        data->player.pa -= 0.1;
        if (data->player.pa < 0)
            data->player.pa += 2 * PI;
        data->player.pdx = cos(data->player.pa) * 3;
        data->player.pdy = sin(data->player.pa) * 3;
    }
    if (keysym == XK_Right)
    {
        data->player.pa += 0.1;
        if (data->player.pa > 2 * PI)
            data->player.pa -= 2 * PI;
        data->player.pdx = cos(data->player.pa) * 3;
        data->player.pdy = sin(data->player.pa) * 3;
    }
    printf("%f\n", data->player.pa);
    render_minimap(data);
    render_player(data);
	return (0);
}