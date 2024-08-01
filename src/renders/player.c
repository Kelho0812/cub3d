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

    y1 = 0;
    draw_fov(data);
    while (y1 < PLAYER_SIZE)
    {
        x1 = 0;
        while (x1 < PLAYER_SIZE)
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

void	horizontal_lines_calc(t_ray *calc, t_dist *dist, t_data *display)
{
	int		itr;

	itr = 0;
	if (calc->ra > PI)
	{
		calc->ry = (((int)display->player.py / BLOCK_SIZE) * BLOCK_SIZE) - 0.0001;
		calc->rx = (display->player.py - calc->ry) * calc->atan + display->player.px;
		calc->ystep = -BLOCK_SIZE;
		calc->xstep = (calc->ystep * -1) * calc->atan;
	}
	if (calc->ra < PI)
	{
		calc->ry = (((int)display->player.py / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		calc->rx = (display->player.py - calc->ry) * calc->atan + display->player.px;
		calc->ystep = BLOCK_SIZE;
		calc->xstep = (calc->ystep * -1) * calc->atan;
	}
	if (calc->ra == PI || calc->ra == 0.0)
	{
		calc->ry = display->player.py;
		calc->rx = display->player.px;
		itr = display->map.height;
	}
	while (itr < display->map.height)
	{
		calc->mx = (int)(calc->rx) / BLOCK_SIZE;
		calc->my = (int)(calc->ry) / BLOCK_SIZE;
		if (calc->mx >= 0 && calc->mx < display->map.width && calc->my >= 0 && calc->my < display->map.height && display->map.full_map_array[calc->my][calc->mx] == '1')
		{
			dist->hx = calc->rx;
			dist->hy = calc->ry;
			dist->distH = distance(display->player.px, display->player.py, dist->hx, dist->hy, calc->ra);
			itr = display->map.height;
		}
		else
		{
			calc->rx += calc->xstep;
			calc->ry += calc->ystep;
			itr++;
		}
	}
}

void	vertical_lines_calc(t_ray *calc, t_dist *dist, t_data * display)
{
	int		itr;

	itr = 0;
	if (calc->ra > P2 && calc->ra < P3)
	{
		calc->rx = (((int)display->player.px / BLOCK_SIZE) * BLOCK_SIZE) - 0.0001;
		calc->ry = (display->player.px - calc->rx) * calc->ntan + display->player.py;
		calc->xstep = -BLOCK_SIZE;
		calc->ystep = (calc->xstep * -1) * calc->ntan;
	}
	if (calc->ra < P2 || calc->ra > P3)
	{
		calc->rx = (((int)display->player.px / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
		calc->ry = (display->player.px - calc->rx) * calc->ntan + display->player.py;
		calc->xstep = BLOCK_SIZE;
		calc->ystep = (calc->xstep * -1) * calc->ntan;
	}
	if (calc->ra == PI || calc->ra == 0)
	{
		calc->ry = display->player.py;
		calc->rx = display->player.px;
		itr = display->map.width;
	}
	while (itr < display->map.width)
	{
		calc->mx = (int)(calc->rx) / BLOCK_SIZE;
		calc->my = (int)(calc->ry) / BLOCK_SIZE;
		if (calc->mx >= 0 && calc->mx < display->map.width && calc->my >= 0 && calc->my < display->map.height && display->map.full_map_array[calc->my][calc->mx] == '1')
		{	
			dist->vx = calc->rx;
			dist->vy = calc->ry;
			dist->distV = distance(display->player.px, display->player.py, dist->vx, dist->vy, calc->ra);
			itr = display->map.width;
        }
		else
		{
			calc->rx += calc->xstep;
			calc->ry += calc->ystep;
			itr++;
		}
	}
}

void draw_fov(t_data *data)
{
    t_ray calc;
	t_dist dist;

    calc.ra = data->player.pa;
	calc.atan = -1/tan(calc.ra);
	calc.ntan = tan(calc.ra) * -1;
	dist.hx = data->player.px;
	dist.hy = data->player.py;
	dist.vx = data->player.px;
	dist.vy = data->player.py;
	dist.distH = 10000000;
	dist.distV = 10000000;
    vertical_lines_calc(&calc, &dist, data);
    horizontal_lines_calc(&calc, &dist, data);
	if (dist.distV < dist.distH)
	{
		calc.rx = dist.vx;
		calc.ry = dist.vy;
	}
	if (dist.distH < dist.distV)
	{
		calc.rx = dist.hx;
		calc.ry = dist.hy;
	}
    draw_line(data->player.px, data->player.py, calc.rx, calc.ry, data);
}
