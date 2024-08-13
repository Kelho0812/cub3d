/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:51:50 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/23 10:29:04 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_handler(WRONG_ARG_NUM);
	init_data(&data);
	parse_and_validate_map(argv[1], &data);
	printf("%d", data.player.direction);
	open_window(&data);
	// create_background_buffer(&data);
	// render_map(&data);
	// render_minimap(&data);
	// render_player(&data);
    // handle_render(&data);
	william_wallace(&data);
	return (0);
}

void	init_data(t_data *data)
{
	init_map(&data->map);
	init_player(&data->player);
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
	data->game.north_texture.info_texture.data = mlx_get_data_addr(data->game.north_texture.texture, \
		&data->game.north_texture.info_texture.bpp, &data->game.north_texture.info_texture.line_len, &data->game.north_texture.info_texture.endian);
	data->game.south_texture.info_texture.data = mlx_get_data_addr(data->game.south_texture.texture, \
		&data->game.south_texture.info_texture.bpp, &data->game.south_texture.info_texture.line_len, &data->game.south_texture.info_texture.endian);
	data->game.east_texture.info_texture.data = mlx_get_data_addr(data->game.east_texture.texture, \
		&data->game.east_texture.info_texture.bpp, &data->game.east_texture.info_texture.line_len, &data->game.east_texture.info_texture.endian);
	data->game.west_texture.info_texture.data = mlx_get_data_addr(data->game.west_texture.texture, \
		&data->game.west_texture.info_texture.bpp, &data->game.west_texture.info_texture.line_len, &data->game.west_texture.info_texture.endian);
}

void	open_window(t_data *data)
{
	data->window.mlx = mlx_init();
	check_textures(data);
	// get_data_textures(data);
	// get_direction(data);
	// data->window.mlx_win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT, "Cub3d - MegaBosses");
	// data->minimap.minimap_wall.texture = mlx_xpm_file_to_image(data->window.mlx, 
	// 	"./src/assets/wall_mini.xpm", &data->minimap.minimap_wall.width, &data->minimap.minimap_wall.height);
	// data->minimap.minimap_wall.info_texture.data = mlx_get_data_addr(data->minimap.minimap_wall.texture, 
	// 	&data->minimap.minimap_wall.info_texture.bpp, &data->minimap.minimap_wall.info_texture.line_len, &data->minimap.minimap_wall.info_texture.endian);
	// data->camera.prev_x = 0;
	// data->player.px += 0.5;
	// data->player.py += 0.5;
	// data->game.move_speed = 0.08;
	// data->game.rotate_speed = 0.05;
}

void	handle_render(t_data *data)
{
	mlx_hook(data->window.mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_hook(data->window.mlx_win, 6, 1L << 6, &handle_mouse_move, data);
	mlx_loop(data->window.mlx);
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
	if (data->game.north_texture.texture == NULL || data->game.south_texture.texture == NULL
		|| data->game.east_texture.texture == NULL || data->game.west_texture.texture == NULL)
		error_handler4(data, TEXTURE_OPEN_ERROR);
	// #TODO check width height
	destroy_images(data);
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