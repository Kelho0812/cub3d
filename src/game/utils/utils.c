/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:52:45 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 11:52:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

void	init_game_values(t_data * data)
{
	data->player.px += 0.5;
	data->player.py += 0.5;
	data->game.move_speed = 0.08;
	data->game.rotate_speed = 0.05;
	create_background_buffer(data);
}

void	check_textures(t_data *data)
{
	data->game.north_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			data->map.north_texture_path, &data->game.north_texture.width,
			&data->game.north_texture.height);
	data->game.south_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			data->map.south_texture_path, &data->game.south_texture.width,
			&data->game.south_texture.height);
	data->game.east_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			data->map.east_texture_path, &data->game.east_texture.width,
			&data->game.east_texture.height);
	data->game.west_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			data->map.west_texture_path, &data->game.west_texture.width,
			&data->game.west_texture.height);
	if (data->game.north_texture.texture == NULL
		|| data->game.south_texture.texture == NULL
		|| data->game.east_texture.texture == NULL
		|| data->game.west_texture.texture == NULL)
		error_handler4(data, TEXTURE_OPEN_ERROR);
	// #TODO check width height
}

void	get_direction(t_data *data)
{
	if (data->player.direction == N)
	{
		data->player.dirX = 0;
		data->player.dirY = -1;
		data->player.planeX = 0.66;
		data->player.planeY = 0;
	}
	else if (data->player.direction == S)
	{
		data->player.dirX = 0;
		data->player.dirY = 1;
		data->player.planeX = -0.66;
		data->player.planeY = 0;
	}
	else if (data->player.direction == W)
	{
		data->player.dirX = 1;
		data->player.dirY = 0;
		data->player.planeX = 0;
		data->player.planeY = 0.66;
	}
	else if (data->player.direction == E)
	{
		data->player.dirX = -1;
		data->player.dirY = 0;
		data->player.planeX = 0;
		data->player.planeY = -0.66;
	}
}

void	get_data_textures(t_data *data)
{
	data->game.north_texture.info_texture.data = mlx_get_data_addr(data->game.north_texture.texture,
			&data->game.north_texture.info_texture.bpp,
			&data->game.north_texture.info_texture.line_len,
			&data->game.north_texture.info_texture.endian);
	data->game.south_texture.info_texture.data = mlx_get_data_addr(data->game.south_texture.texture,
			&data->game.south_texture.info_texture.bpp,
			&data->game.south_texture.info_texture.line_len,
			&data->game.south_texture.info_texture.endian);
	data->game.east_texture.info_texture.data = mlx_get_data_addr(data->game.east_texture.texture,
			&data->game.east_texture.info_texture.bpp,
			&data->game.east_texture.info_texture.line_len,
			&data->game.east_texture.info_texture.endian);
	data->game.west_texture.info_texture.data = mlx_get_data_addr(data->game.west_texture.texture,
			&data->game.west_texture.info_texture.bpp,
			&data->game.west_texture.info_texture.line_len,
			&data->game.west_texture.info_texture.endian);
}

void	destroy_images(t_data *data)
{
	if (data->game.north_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.north_texture.texture);
	if (data->game.south_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.south_texture.texture);
	if (data->game.east_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.east_texture.texture);
	if (data->game.west_texture.texture != NULL)
		mlx_destroy_image(data->window.mlx, data->game.west_texture.texture);
}
