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
		ptr = data->game.map_img.data + (x * (data->game.map_img.bpp / 8)) + (y
				* data->game.map_img.line_len);
		*(unsigned int *)ptr = color;
	}
}

void	define_texture(t_dda_values dda_values, t_data data, t_texture *ptr)
{
	if (dda_values.side == 1 && data.rays.rayDirY < 0)
		*ptr = data.game.south_texture;
	else if (dda_values.side == 1 && data.rays.rayDirY > 0)
		*ptr = data.game.north_texture;
	else if (dda_values.side == 0 && data.rays.rayDirX < 0)
		*ptr = data.game.west_texture;
	else if (dda_values.side == 0 && data.rays.rayDirX > 0)
		*ptr = data.game.east_texture;
}

void	define_values_to_draw_texture(t_texture_values *draw_values, t_texture ptr, t_dda_values dda_values, t_data *data)
{
	draw_values->drawStart = HEIGHT / 2 - dda_values.lineHeight / 2;
	if (draw_values->drawStart < 0)
		draw_values->drawStart = 0;
	draw_values->drawEnd = HEIGHT / 2 + dda_values.lineHeight / 2;
	if (draw_values->drawEnd >= HEIGHT)
		draw_values->drawEnd = HEIGHT - 1;
	if (dda_values.side == 0)
		draw_values->wallX = data->player.py + data->dist.perpWallDist * data->rays.rayDirY;
	else
		draw_values->wallX = data->player.px + data->dist.perpWallDist * data->rays.rayDirX;
	draw_values->wallX -= floor((draw_values->wallX));
	draw_values->texX = (int)(draw_values->wallX * (double)ptr.width);
	if (dda_values.side == 0 && data->rays.rayDirX > 0)
		draw_values->texX = ptr.width - draw_values->texX - 1;
	if (dda_values.side == 1 && data->rays.rayDirY < 0)
		draw_values->texX = ptr.width - draw_values->texX - 1;
	draw_values->step = 1.0 * ptr.height / dda_values.lineHeight;
	draw_values->texPos = (draw_values->drawStart - HEIGHT / 2 + dda_values.lineHeight / 2) * draw_values->step;
}

void	draw_stripe(t_dda_values dda_values, int x, t_data *data)
{
	int					i;
	int 				color;
	t_texture 			ptr;
	t_texture_values 	draw_values;

	define_texture(dda_values, *data, &ptr);
	define_values_to_draw_texture(&draw_values, ptr, dda_values, data);
	i = draw_values.drawStart;
	while (i < draw_values.drawEnd)
	{
		draw_values.texY = (int)draw_values.texPos & (data->game.north_texture.height - 1);
		draw_values.texPos += draw_values.step;
		color = *(int *)(ptr.info_texture.data + draw_values.texY \
			* ptr.info_texture.line_len + draw_values.texX * (ptr.info_texture.bpp / 8));
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
