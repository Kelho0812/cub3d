/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:35:48 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 12:35:48 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	my_pixel_put(int x, int y, int color, t_data *data)
{
	char	*ptr;

	ptr = NULL;
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		ptr = data->map.map_img.data + (x * (data->map.map_img.bpp / 8)) + (y
				* data->map.map_img.line_len);
		*(unsigned int *)ptr = color;
	}
}

void	draw_stripe(t_dda_values dda_values, int x, t_data *data)
{
	int drawStart;
	int drawEnd;
	double wallX;
	int	i;
	int texX;
	int texY;
	int color;
	t_texture ptr;

	if (dda_values.side == 1 && data->rays.rayDirY < 0)
		ptr = data->game.north_texture;
	else if (dda_values.side == 1 && data->rays.rayDirY > 0)
		ptr = data->game.east_texture;
	else if (dda_values.side == 0 && data->rays.rayDirX < 0)
		ptr = data->game.south_texture;
	else if (dda_values.side == 0 && data->rays.rayDirX > 0)
		ptr = data->game.west_texture;
	drawStart = -dda_values.lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = dda_values.lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	if (dda_values.side == 0)
		wallX = data->player.py + data->dist.perpWallDist * data->rays.rayDirY;
	else
		wallX = data->player.px + data->dist.perpWallDist * data->rays.rayDirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)data->game.north_texture.width);
	if (dda_values.side == 0 && data->rays.rayDirX > 0)
		texX = data->game.north_texture.width - texX - 1;
	if (dda_values.side == 1 && data->rays.rayDirY < 0)
		texX = data->game.north_texture.width - texX - 1;
	double step = 1.0 * data->game.north_texture.height / dda_values.lineHeight;
	double texPos = (drawStart - HEIGHT / 2 + dda_values.lineHeight / 2) * step;
	i = drawStart;
	while (i < drawEnd)
	{
		texY = (int)texPos & (data->game.north_texture.height - 1);
		texPos += step;
		color = *(int *)(ptr.info_texture.data + texY \
			* ptr.info_texture.line_len + texX * (ptr.info_texture.bpp / 8));
		my_pixel_put(x, i, color, data);
		i++;
	}
}

void render_background(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y, data->buffer_background[y * WIDTH + x], data);
			x++;
		} 
		y++;
	}
}
