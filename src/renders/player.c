/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:05:19 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 16:05:19 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    render_player(t_data *data)
{
    int x1;
    int y1;
    int x = data->player.px;
    int y = data->player.py;

    y1 = 0 - PLAYER_SIZE / 2;
    draw_fov(data);
    while (y1 < PLAYER_SIZE / 2)
    {
        x1 = 0 - PLAYER_SIZE / 2;
        while (x1 < PLAYER_SIZE / 2)
        {
            if (x + x1 < WIDTH && y + y1 < HEIGHT)
                my_pixel_put(x + x1, y + y1, 0xFF0000, data);
            x1++;
        }
        y1++;
    }
    mlx_put_image_to_window(data->window.mlx, data->window.mlx_win, data->map.map_img.mlx_img, 0, 0);
    mlx_destroy_image(data->window.mlx, data->map.map_img.mlx_img);
}

float	distance(float ax, float ay, float bx, float by, float ang)
{
	(void) ang;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	horizontal_lines_calc(t_data *data)
{
	int		itr;

	itr = 0;
	if (data->rays.ra > PI)
	{
		data->rays.ry = (((int)data->player.py / BLOCK_SIZE) * BLOCK_SIZE) - 0.0001;
		data->rays.rx = (data->player.py - data->rays.ry) * data->rays.atan + data->player.px;
		data->rays.ystep = -BLOCK_SIZE;
		data->rays.xstep = (data->rays.ystep * -1) * data->rays.atan;
	}
	if (data->rays.ra < PI)
	{
		data->rays.ry = (((int)data->player.py / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		data->rays.rx = (data->player.py - data->rays.ry) * data->rays.atan + data->player.px;
		data->rays.ystep = BLOCK_SIZE;
		data->rays.xstep = (data->rays.ystep * -1) * data->rays.atan;
	}
	if (data->rays.ra == PI || data->rays.ra == 0.0)
	{
		data->rays.ry = data->player.py;
		data->rays.rx = data->player.px;
		itr = data->map.height;
	}
	while (itr < data->map.height)
	{
		data->rays.mx = (int)(data->rays.rx) / BLOCK_SIZE;
		data->rays.my = (int)(data->rays.ry) / BLOCK_SIZE;
		if (data->rays.mx >= 0 && data->rays.mx < data->map.width && data->rays.my >= 0 && data->rays.my < data->map.height && data->map.full_map_array[data->rays.my][data->rays.mx] == '1')
		{
			data->dist.hx = data->rays.rx;
			data->dist.hy = data->rays.ry;
			data->dist.distH = distance(data->player.px, data->player.py, data->dist.hx, data->dist.hy, data->rays.ra);
			itr = data->map.height;
		}
		else
		{
			data->rays.rx += data->rays.xstep;
			data->rays.ry += data->rays.ystep;
			itr++;
		}
	}
}

void	vertical_lines_calc(t_data * data)
{
	int		itr;

	itr = 0;
	if (data->rays.ra > P2 && data->rays.ra < P3)
	{
		data->rays.rx = (((int)data->player.px / BLOCK_SIZE) * BLOCK_SIZE) - 0.0001;
		data->rays.ry = (data->player.px - data->rays.rx) * data->rays.ntan + data->player.py;
		data->rays.xstep = -BLOCK_SIZE;
		data->rays.ystep = (data->rays.xstep * -1) * data->rays.ntan;
	}
	if (data->rays.ra < P2 || data->rays.ra > P3)
	{
		data->rays.rx = (((int)data->player.px / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		data->rays.ry = (data->player.px - data->rays.rx) * data->rays.ntan + data->player.py;
		data->rays.xstep = BLOCK_SIZE;
		data->rays.ystep = (data->rays.xstep * -1) * data->rays.ntan;
	}
	if (data->rays.ra == PI || data->rays.ra == 0)
	{
		data->rays.ry = data->player.py;
		data->rays.rx = data->player.px;
		itr = data->map.width;
	}
	while (itr < data->map.width)
	{
		data->rays.mx = (int)(data->rays.rx) / BLOCK_SIZE;
		data->rays.my = (int)(data->rays.ry) / BLOCK_SIZE;
		if (data->rays.mx >= 0 && data->rays.mx < data->map.width && data->rays.my >= 0 && data->rays.my < data->map.height && data->map.full_map_array[data->rays.my][data->rays.mx] == '1')
		{	
			data->dist.vx = data->rays.rx;
			data->dist.vy = data->rays.ry;
			data->dist.distV = distance(data->player.px, data->player.py, data->dist.vx, data->dist.vy, data->rays.ra);
			itr = data->map.width;
        }
		else
		{
			data->rays.rx += data->rays.xstep;
			data->rays.ry += data->rays.ystep;
			itr++;
		}
	}
}

void	init_default_values(t_data * data)
{
	data->rays.atan = -1/tan(data->rays.ra);
	data->rays.ntan = tan(data->rays.ra) * -1;
	data->dist.hx = data->player.px;
	data->dist.hy = data->player.py;
	data->dist.vx = data->player.px;
	data->dist.vy = data->player.py;
	data->dist.distH = 10000000;
	data->dist.distV = 10000000;
}

void draw_fov(t_data *data)
{
	int	raycasted;

	raycasted = 0;
    data->rays.ra = data->player.pa - (DEGRESS * 30);
	if (data->rays.ra < 0)
		data->rays.ra += 2 * PI;
	while (raycasted < 60)
	{
		init_default_values(data);
		vertical_lines_calc(data);
		horizontal_lines_calc(data);
		if (data->dist.distH < data->dist.distV)
		{
			data->rays.rx = data->dist.hx;
			data->rays.ry = data->dist.hy;
		}
		if (data->dist.distV < data->dist.distH)
		{
			data->rays.rx = data->dist.vx;
			data->rays.ry = data->dist.vy;
		}
		draw_line(data->player.px, data->player.py, data->rays.rx, data->rays.ry, data);
		data->rays.ra += DEGRESS;
		if (data->rays.ra > 2 * PI)
            data->rays.ra -= 2 * PI;
		raycasted++;
	}
}
