/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:45:41 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 12:45:41 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	handle_render(t_data *data)
{
	mlx_hook(data->window.mlx_win, KeyPress, KeyPressMask, &handle_keypress,
		data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close,
		data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close,
		data);
	mlx_hook(data->window.mlx_win, 6, 1L << 6, &handle_mouse, data);
	mlx_do_key_autorepeaton(data->window.mlx);
	// mlx_mouse_hide(data->window.mlx, data->window.mlx_win);
	mlx_loop_hook(data->window.mlx, render_game, data);
	mlx_loop(data->window.mlx);
	mlx_destroy_window(data->window.mlx, data->window.mlx_win);
	mlx_destroy_display(data->window.mlx);
	free(data->window.mlx);
}
