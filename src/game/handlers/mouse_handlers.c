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
    (void)y;
    if (x > data->game.mouse_position.prev_x)
        move_right(data);
    else if (x < data->game.mouse_position.prev_x)
        move_left(data);
    data->game.mouse_position.prev_x = x;
    return (0);
}