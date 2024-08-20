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

	temp_height = data->game.wall1.height;
	temp_width = data->game.wall1.width;
	if (temp_height != data->game.wall2.height
		|| temp_height != data->game.wall4.height
		|| temp_height != data->game.wall3.height
		|| temp_width != data->game.wall2.width
		|| temp_width != data->game.wall4.width
		|| temp_width != data->game.wall3.width)
		return (0);
	return (1);
}

void	check_textures(t_data *data)
{
	data->game.wall1.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/wall1.xpm", &data->game.wall1.width,
			&data->game.wall1.height);
	data->game.wall2.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/wall2.xpm", &data->game.wall2.width,
			&data->game.wall2.height);
	data->game.wall3.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/wall3.xpm", &data->game.wall3.width,
			&data->game.wall3.height);
	data->game.wall4.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/wall4.xpm", &data->game.wall4.width,
			&data->game.wall4.height);
	data->game.wall5.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/wall5.xpm", &data->game.wall5.width,
			&data->game.wall5.height);
	data->game.celling_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/celling.xpm", &data->game.celling_texture.width,
			&data->game.celling_texture.height);
	data->game.floor_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/floor.xpm", &data->game.floor_texture.width,
			&data->game.floor_texture.height);
	data->game.weapon_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/weapon.xpm", &data->game.weapon_texture.width,
			&data->game.weapon_texture.height);
	if (data->game.wall1.texture == NULL
		|| data->game.wall2.texture == NULL
		|| data->game.wall3.texture == NULL
		|| data->game.wall4.texture == NULL
		|| data->game.celling_texture.texture == NULL
		|| data->game.floor_texture.texture == NULL
		|| data->game.weapon_texture.texture == NULL)
		error_handler4(data, TEXTURE_OPEN_ERROR);
	if (!check_dimension_texture(data))
		error_handler4(data, TEXTURE_OPEN_ERROR);
}

void	get_direction2(t_data *data)
{
	if (data->player.direction == W)
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else if (data->player.direction == E)
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}

void	get_direction(t_data *data)
{
	if (data->player.direction == N)
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (data->player.direction == S)
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else
		get_direction2(data);
}

void	get_data_textures(t_data *data)
{
	data->game.wall1.info_texture.data = mlx_get_data_addr(
			data->game.wall1.texture,
			&data->game.wall1.info_texture.bpp,
			&data->game.wall1.info_texture.line_len,
			&data->game.wall1.info_texture.endian);
	data->game.wall2.info_texture.data = mlx_get_data_addr(
			data->game.wall2.texture,
			&data->game.wall2.info_texture.bpp,
			&data->game.wall2.info_texture.line_len,
			&data->game.wall2.info_texture.endian);
	data->game.wall3.info_texture.data = mlx_get_data_addr(
			data->game.wall3.texture,
			&data->game.wall3.info_texture.bpp,
			&data->game.wall3.info_texture.line_len,
			&data->game.wall3.info_texture.endian);
	data->game.wall4.info_texture.data = mlx_get_data_addr(
			data->game.wall4.texture,
			&data->game.wall4.info_texture.bpp,
			&data->game.wall4.info_texture.line_len,
			&data->game.wall4.info_texture.endian);
	data->game.wall5.info_texture.data = mlx_get_data_addr(
			data->game.wall5.texture,
			&data->game.wall5.info_texture.bpp,
			&data->game.wall5.info_texture.line_len,
			&data->game.wall5.info_texture.endian);
	data->game.celling_texture.info_texture.data = mlx_get_data_addr(
			data->game.celling_texture.texture,
			&data->game.celling_texture.info_texture.bpp,
			&data->game.celling_texture.info_texture.line_len,
			&data->game.celling_texture.info_texture.endian);
	data->game.floor_texture.info_texture.data = mlx_get_data_addr(
			data->game.floor_texture.texture,
			&data->game.floor_texture.info_texture.bpp,
			&data->game.floor_texture.info_texture.line_len,
			&data->game.floor_texture.info_texture.endian);
	data->game.weapon_texture.info_texture.data = mlx_get_data_addr(
			data->game.weapon_texture.texture,
			&data->game.weapon_texture.info_texture.bpp,
			&data->game.weapon_texture.info_texture.line_len,
			&data->game.weapon_texture.info_texture.endian);
}
