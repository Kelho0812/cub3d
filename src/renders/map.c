/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:55:51 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/11 18:55:51 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_distances(int mapX, int mapY, int *stepX, int *stepY, t_data * data)
{
	if (data->rays.rayDirX == 0)
		data->dist.deltaDistX = 1e30;
	else
		data->dist.deltaDistX = fabs(1 / data->rays.rayDirX);
	if (data->rays.rayDirY == 0)
		data->dist.deltaDistY = 1e30;
	else
		data->dist.deltaDistY = fabs(1 / data->rays.rayDirY);
	if (data->rays.rayDirX < 0)
	{
		*stepX = -1;
		data->dist.sideDistX = (data->player.px - mapX) * data->dist.deltaDistX;
	}
	else
	{
		*stepX = 1;
		data->dist.sideDistX = (mapX + 1.0 - data->player.px) * data->dist.deltaDistX;
	}
	if (data->rays.rayDirY < 0)
	{
		*stepY = -1;
		data->dist.sideDistY = (data->player.py - mapY) * data->dist.deltaDistY;
	}
	else
	{
		*stepY = 1;
		data->dist.sideDistY = (mapY + 1.0 - data->player.py) * data->dist.deltaDistY;
	}
}

void	draw_stripe(int lineHeight, int x, int side, t_data *data)
{
	int drawStart;
	int drawEnd;
	double wallX;
	int	i;
	int texX;
	int texY;
	int color;

	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	if (side == 0)
		wallX = data->player.py + data->dist.perpWallDist * data->rays.rayDirY;
	else
		wallX = data->player.px + data->dist.perpWallDist * data->rays.rayDirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)data->minimap.game_wall.width);
	if (side == 0 && data->rays.rayDirX > 0)
		texX = data->minimap.game_wall.width - texX - 1;
	if (side == 1 && data->rays.rayDirY < 0)
		texX = data->minimap.game_wall.width - texX - 1;
	double step = 1.0 * data->minimap.game_wall.height / lineHeight;
	double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
	i = drawStart;
	while (i < drawEnd)
	{
		texY = (int)texPos & (data->minimap.game_wall.height - 1);
		texPos += step;
		color = *(int *)(data->minimap.game_wall.info_texture.data + texY \
			* data->minimap.game_wall.info_texture.line_len + texX * (data->minimap.game_wall.info_texture.bpp / 8));
		if (data->dist.perpWallDist > 5)
			color = (color >> 2) & 8355711;
		else if (data->dist.perpWallDist > 3)
			color = (color >> 1) & 8355711;
		my_pixel_put(x, i, color, data);
		i++;
	}
}

void render_background_buffer(t_data *data)
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

void create_background_buffer(t_data *data)
{
	int x;
	int y;
	int celling;
	int floor;

	celling = data->map.ceiling_color.R << 16 | data->map.ceiling_color.G << 8 | data->map.ceiling_color.B;
	floor = data->map.floor_color.R << 16 | data->map.floor_color.G << 8 | data->map.floor_color.B;
	data->buffer_background = malloc(WIDTH * HEIGHT * sizeof(unsigned int));
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				data->buffer_background[y * WIDTH + x] = celling;
			else
				data->buffer_background[y * WIDTH + x] = floor;
			x++;
		} 
		y++;
	}
}

void render_map(t_data *data)
{
	int	x = 0;
	int hit;
	int side;
	int	mapX;
	int	mapY;
	int stepX;
    int stepY;
	int lineHeight;

	data->map.map_img.mlx_img = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->map.map_img.data = mlx_get_data_addr(data->map.map_img.mlx_img, &data->map.map_img.bpp, &data->map.map_img.line_len, &data->map.map_img.endian);
	render_background_buffer(data);
	while (x < WIDTH)
	{
		hit = 0;
		mapX = (int)data->player.px;
		mapY = (int)data->player.py;
		data->rays.cameraX = 2 * x / (double)WIDTH - 1;
		data->rays.rayDirX = data->player.dirX + data->player.planeX * data->rays.cameraX;
		data->rays.rayDirY = data->player.dirY + data->player.planeY * data->rays.cameraX;
		calculate_distances(mapX, mapY, &stepX, &stepY, data);
		while (hit == 0)
		{
			if (data->dist.sideDistX < data->dist.sideDistY)
			{
				data->dist.sideDistX += data->dist.deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				data->dist.sideDistY += data->dist.deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map.full_map_array[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
			data->dist.perpWallDist = data->dist.sideDistX - data->dist.deltaDistX;
		else
			data->dist.perpWallDist = data->dist.sideDistY - data->dist.deltaDistY;
		lineHeight = (int)(HEIGHT / data->dist.perpWallDist);
		draw_stripe(lineHeight, x, side, data);
		x++;
	}
}
