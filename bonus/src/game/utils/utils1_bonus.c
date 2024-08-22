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

#include "../../../includes/cub3d_bonus.h"

static void	check_errors_textures(t_data *data);
static int	check_dimension_texture(t_data *data);

void	get_textures(t_data *data)
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
	data->game.weapon_texture.texture = mlx_xpm_file_to_image(data->window.mlx,
			"./textures/weapon.xpm", &data->game.weapon_texture.width,
			&data->game.weapon_texture.height);
	check_errors_textures(data);
}

void	get_data_textures_wall(t_data *data)
{
	data->game.wall1.info.data = mlx_get_data_addr(
			data->game.wall1.texture,
			&data->game.wall1.info.bpp,
			&data->game.wall1.info.line_len,
			&data->game.wall1.info.endian);
	data->game.wall2.info.data = mlx_get_data_addr(
			data->game.wall2.texture,
			&data->game.wall2.info.bpp,
			&data->game.wall2.info.line_len,
			&data->game.wall2.info.endian);
	data->game.wall3.info.data = mlx_get_data_addr(
			data->game.wall3.texture,
			&data->game.wall3.info.bpp,
			&data->game.wall3.info.line_len,
			&data->game.wall3.info.endian);
	data->game.wall4.info.data = mlx_get_data_addr(
			data->game.wall4.texture,
			&data->game.wall4.info.bpp,
			&data->game.wall4.info.line_len,
			&data->game.wall4.info.endian);
	data->game.wall5.info.data = mlx_get_data_addr(
			data->game.wall5.texture,
			&data->game.wall5.info.bpp,
			&data->game.wall5.info.line_len,
			&data->game.wall5.info.endian);
}

void	get_data_texture_weapon(t_data *data)
{
	data->game.weapon_texture.info.data = mlx_get_data_addr(
			data->game.weapon_texture.texture,
			&data->game.weapon_texture.info.bpp,
			&data->game.weapon_texture.info.line_len,
			&data->game.weapon_texture.info.endian);
}

static int	check_dimension_texture(t_data *data)
{
	int	temp_height;
	int	temp_width;

	temp_height = data->game.wall1.height;
	temp_width = data->game.wall1.width;
	if (temp_height != data->game.wall2.height
		|| temp_height != data->game.wall3.height
		|| temp_height != data->game.wall4.height
		|| temp_height != data->game.wall5.height
		|| temp_width != data->game.wall2.width
		|| temp_width != data->game.wall3.width
		|| temp_width != data->game.wall4.width
		|| temp_width != data->game.wall5.width)
		return (0);
	return (1);
}

static void	check_errors_textures(t_data *data)
{
	if (data->game.wall1.texture == NULL
		|| data->game.wall2.texture == NULL
		|| data->game.wall3.texture == NULL
		|| data->game.wall4.texture == NULL
		|| data->game.wall5.texture == NULL
		|| data->game.weapon_texture.texture == NULL
		|| !create_frames(data)
		|| !create_frames_torch(data))
		error_handler4(data, TEXTURE_OPEN_ERROR);
	if (!check_dimension_texture(data))
		error_handler4(data, TEXTURE_OPEN_ERROR);
}
