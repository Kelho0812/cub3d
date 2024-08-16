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
    if (y > data->game.mouse_position.prev_y)
        data->game.step_height -= 2;
    else if (y < data->game.mouse_position.prev_y)
        data->game.step_height += 2;
    if (x > data->game.mouse_position.prev_x)
        turn_right(data);
    else if (x < data->game.mouse_position.prev_x)
        turn_left(data);
    data->game.mouse_position.prev_x = x;
    data->game.mouse_position.prev_y = y;
    return (0);
}