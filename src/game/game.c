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
	create_frames(data);
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

int	render_game(void *param)
{
	t_data			*data;
	t_dda_values	dda_values;
	int				x;

	x = 0;
	data = (t_data *)param;
	update_time(data);
	create_image(data);
	// render_floor(data);
	// render_celling(data);
	while (x < WIDTH)
	{
		init_values_dda(x, &dda_values, data);
		calculate_distances(&dda_values, data);
		execute_dda(&dda_values, data, x);
		x++;
	}
	render_minimap(data);
	render_player(data);
	render_weapon(data);
	put_image_to_window(data);
	check_door(data);
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
