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

void	my_pixel_put(int x, int y, int color, t_img img)
{
	char	*ptr;

	ptr = NULL;
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		ptr = img.data + (x * (img.bpp / 8)) + (y * img.line_len);
		*(unsigned int *)ptr = color;
	}
}

void	define_texture(t_rec_val temp, t_data data, t_texture *ptr)
{
	if (data.map.full_map_array[temp.map_y][temp.map_x] == '1')
		*ptr = data.game.wall1;
	else if (data.map.full_map_array[temp.map_y][temp.map_x] == '2')
		*ptr = data.game.wall2;
	else if (data.map.full_map_array[temp.map_y][temp.map_x] == '3')
		*ptr = data.game.wall3;
	else if (data.map.full_map_array[temp.map_y][temp.map_x] == '4')
		*ptr = data.game.wall4;
	else if (data.map.full_map_array[temp.map_y][temp.map_x] == '5')
		*ptr = data.game.wall5;
	else if (data.map.full_map_array[temp.map_y][temp.map_x] == '6')
		*ptr = data.game.animation.frames->texture;
}

void	define_values_to_draw_texture(t_texture_values *draw_values,
		t_texture ptr, t_rec_val temp, t_data *data)
{
	draw_values->draw_start = HEIGHT / 2 - (temp.line_height / 2)
		+ data->game.step_height;
	if (draw_values->draw_start < 0)
		draw_values->draw_start = 0;
	draw_values->draw_end = HEIGHT / 2 + (temp.line_height / 2)
		+ data->game.step_height;
	if (draw_values->draw_end >= HEIGHT)
		draw_values->draw_end = HEIGHT - 1;
	if (temp.side == 0)
		draw_values->wall_x = data->player.py + temp.wall_dist
			* data->rays.ray_dir_y;
	else
		draw_values->wall_x = data->player.px + temp.wall_dist
			* data->rays.ray_dir_x;
	draw_values->wall_x -= floor((draw_values->wall_x));
	draw_values->tex_x = (int)(draw_values->wall_x * (double)ptr.width);
	if (temp.side == 0 && data->rays.ray_dir_x > 0)
		draw_values->tex_x = ptr.width - draw_values->tex_x - 1;
	if (temp.side == 1 && data->rays.ray_dir_y < 0)
		draw_values->tex_x = ptr.width - draw_values->tex_x - 1;
	draw_values->step = 1.0 * ptr.height / temp.line_height;
	draw_values->tex_pos = ((draw_values->draw_start - data->game.step_height)
			- HEIGHT / 2 + temp.line_height / 2) * draw_values->step;
}

void	draw_stripe(int x, t_data *data, t_rec_val *temp)
{
	int					i;
	int					color;
	t_texture			ptr;
	t_texture_values	draw_values;

	define_texture(*temp, *data, &ptr);
	define_values_to_draw_texture(&draw_values, ptr, *temp, data);
	i = draw_values.draw_start;
	while (i < draw_values.draw_end)
	{
		draw_values.tex_y = (int)draw_values.tex_pos & (data->game.wall1.height
				- 1);
		draw_values.tex_pos += draw_values.step;
		color = *(int *)(ptr.info.data + draw_values.tex_y
				* ptr.info.line_len + draw_values.tex_x
				* (ptr.info.bpp / 8));
		if (temp->wall_dist > 2)
			color = shadow_dist(color, temp->wall_dist);
		if (color > 0x000000)
			my_pixel_put(x, i, color, data->game.map_img);
		i++;
	}
}

void	render_background(t_data *data)
{
	int	x;
	int	y;
	int	celling;
	int	floor;
	int	color;

	celling = CEILING_COLOR;
	floor = FLOOR_COLOR;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2 + data->game.step_height)
				color = shadow_celling(celling, y);
			else
				color = shadow_floor(floor, y);
			my_pixel_put(x, y, color, data->game.map_img);
			x++;
		}
		y++;
	}
}
