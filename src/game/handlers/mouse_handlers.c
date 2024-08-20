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

#include "../../../includes/cub3d.h"

int handle_mouse(int x, int y, t_data *data)
{
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    if (x == 0)
        mlx_mouse_move(data->window.mlx, data->window.mlx_win, WIDTH - 2, y);
    if (y == 10)
        mlx_mouse_move(data->window.mlx, data->window.mlx_win, x, HEIGHT - 2);
    if (x == WIDTH - 1)
        mlx_mouse_move(data->window.mlx, data->window.mlx_win, 1, y);
    if (y == HEIGHT - 70)
        mlx_mouse_move(data->window.mlx, data->window.mlx_win, x, 1);
    if (y > data->game.mouse_position.prev_y)
        data->game.step_height -= 5;
    else if (y < data->game.mouse_position.prev_y)
        data->game.step_height += 5;
    if (x > data->game.mouse_position.prev_x)
        turn_right(data);
    else if (x < data->game.mouse_position.prev_x)
        turn_left(data);
    data->game.mouse_position.prev_x = x;
    data->game.mouse_position.prev_y = y;
    return (0);
}