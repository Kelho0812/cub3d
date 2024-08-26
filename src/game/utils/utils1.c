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

static int	check_dimension_texture(t_data *data)
{
	int	temp_height;
	int	temp_width;

	temp_height = data->game.north_texture.height;
	temp_width = data->game.north_texture.width;
	if (temp_height != data->game.south_texture.height
		|| temp_height != data->game.west_texture.height
		|| temp_height != data->game.east_texture.height
		|| temp_width != data->game.south_texture.width
		|| temp_width != data->game.west_texture.width
		|| temp_width != data->game.east_texture.width)
		return (0);
	return (1);
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
	if (!check_dimension_texture(data))
		error_handler4(data, TEXTURE_OPEN_ERROR);
}

void	get_direction2(t_data *data)
{
	if (data->player.direction == W)
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.right_x = 0;
		data->player.right_y = -1;
		data->player.left_x = 0;
		data->player.left_y = 1;
		data->player.plane_x = 0;
		data->player.plane_y = -1;
	}
	else if (data->player.direction == E)
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.right_x = 0;
		data->player.right_y = 1;
		data->player.left_x = 0;
		data->player.left_y = -1;
		data->player.plane_x = 0;
		data->player.plane_y = 1;
	}
}

void	get_direction(t_data *data)
{
	if (data->player.direction == N)
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.right_x = 1;
		data->player.right_y = 0;
		data->player.left_x = -1;
		data->player.left_y = 0;
		data->player.plane_x = 1;
		data->player.plane_y = 0;
	}
	else if (data->player.direction == S)
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.right_x = -1;
		data->player.right_y = 0;
		data->player.left_x = 1;
		data->player.left_y = 0;
		data->player.plane_x = -1;
		data->player.plane_y = 0;
	}
	else
		get_direction2(data);
}

void	get_data_textures(t_data *data)
{
	data->game.north_texture.info_texture.data = mlx_get_data_addr(
			data->game.north_texture.texture,
			&data->game.north_texture.info_texture.bpp,
			&data->game.north_texture.info_texture.line_len,
			&data->game.north_texture.info_texture.endian);
	data->game.south_texture.info_texture.data = mlx_get_data_addr(
			data->game.south_texture.texture,
			&data->game.south_texture.info_texture.bpp,
			&data->game.south_texture.info_texture.line_len,
			&data->game.south_texture.info_texture.endian);
	data->game.east_texture.info_texture.data = mlx_get_data_addr(
			data->game.east_texture.texture,
			&data->game.east_texture.info_texture.bpp,
			&data->game.east_texture.info_texture.line_len,
			&data->game.east_texture.info_texture.endian);
	data->game.west_texture.info_texture.data = mlx_get_data_addr(
			data->game.west_texture.texture,
			&data->game.west_texture.info_texture.bpp,
			&data->game.west_texture.info_texture.line_len,
			&data->game.west_texture.info_texture.endian);
}
