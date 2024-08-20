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

static void	create_image(t_data *data);
static void	put_image_to_window(t_data *data);

void	play_game(t_data *data)
{
	open_window(data);
	init_game_values(data);
	render_game(data);
	handle_render(data);
}

void	open_window(t_data *data)
{
	data->window.mlx = mlx_init();
	check_textures(data);
	get_data_textures(data);
	get_direction(data);
	data->window.mlx_win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT,
			"Cub3d - OsBrabos");
}

void	render_weapon(t_data *data)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	color;

	x1 = WIDTH / 2 - (data->game.weapon_texture.width / 2);
	y1 = HEIGHT - data->game.weapon_texture.height;
	y = 0;
	while (y < data->game.weapon_texture.height)
	{
		x = 0;
		while (x < data->game.weapon_texture.width)
		{
			color = *(int *)(data->game.weapon_texture.info_texture.data + y
				* data->game.weapon_texture.info_texture.line_len + x
				* (data->game.weapon_texture.info_texture.bpp / 8));
			if (color != -16777216)
				my_pixel_put(x1 + x, y1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
}

void	render_mira(t_data *data)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	color;

	x1 = WIDTH / 2 - 10;
	y1 = HEIGHT / 2 - 10;
	y = 0;
	while (y < 3)
	{
		x = 1;
		while (x < 20)
		{
			color = 0xFFFFFF;
			my_pixel_put(x1 + x, HEIGHT / 2 - 1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
	y = 1;
	while (y < 20)
	{
		x = 0;
		while (x < 3)
		{
			color = 0xFFFFFF;
			my_pixel_put(WIDTH / 2 - 1 + x, y1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
}

int	render_game(void *param)
{
	t_data *data;
	t_dda_values	dda_values;
	int				x;

	x = 0;
	data = (t_data*)param;
	update_time(data);
	create_image(data);
	render_floor(data);
	render_celling(data);
	while (x < WIDTH)
	{
		init_values_dda(x, &dda_values, data);
		calculate_distances(&dda_values, data);
		execute_dda(&dda_values, data);
		find_distance_to_wall(&dda_values, data);
		draw_stripe(dda_values, x, data);
		x++;
	}
	render_minimap(data);
	render_player(data);
	render_weapon(data);
	render_mira(data);
	put_image_to_window(data);
	return (0);
}

static void	create_image(t_data *data)
{
	data->game.map_img.mlx_img = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->game.map_img.data = mlx_get_data_addr(data->game.map_img.mlx_img,
			&data->game.map_img.bpp, &data->game.map_img.line_len,
			&data->game.map_img.endian);
}

static void	put_image_to_window(t_data *data)
{
	mlx_put_image_to_window(data->window.mlx, data->window.mlx_win,
		data->game.map_img.mlx_img, 0, 0);
	mlx_destroy_image(data->window.mlx, data->game.map_img.mlx_img);
}
