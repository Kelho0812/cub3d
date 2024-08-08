/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:07:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 16:07:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	max_step(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

float	positive(float n)
{
	if (n < 0)
		return (n *= -1);
	return (n);
}

void	draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float x_step;
	float y_step;
	float max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = max_step(positive(x_step), positive(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_pixel_put(x, y, 0x00FF00, data);
		x += x_step;
		y += y_step;
	}
}