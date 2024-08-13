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
	printf("%d,", data.map.ceiling_color.R);
	printf("%d,", data.map.ceiling_color.G);
	printf("%d\n", data.map.ceiling_color.B);
	open_window(&data);
	create_background_buffer(&data);
	render_map(&data);
	render_minimap(&data);
	render_player(&data);
    handle_render(&data);
	william_wallace(&data);
	return (0);
}

void	init_data(t_data *data)
{
	init_map(&data->map);
	init_player(&data->player);
}

void	open_window(t_data *data)
{
	data->window.mlx = mlx_init();
	data->window.mlx_win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT, "Cub3d - MegaBosses");
	data->minimap.minimap_wall.texture = mlx_xpm_file_to_image(data->window.mlx, \
		"./src/assets/wall_mini.xpm", &data->minimap.minimap_wall.width, &data->minimap.minimap_wall.height);
	data->minimap.minimap_wall.info_texture.data = mlx_get_data_addr(data->minimap.minimap_wall.texture, \
		&data->minimap.minimap_wall.info_texture.bpp, &data->minimap.minimap_wall.info_texture.line_len, &data->minimap.minimap_wall.info_texture.endian);
	data->minimap.game_wall.texture = mlx_xpm_file_to_image(data->window.mlx, \
		"./src/assets/wall_map.xpm", &data->minimap.game_wall.width, &data->minimap.game_wall.height);
	data->minimap.game_wall.info_texture.data = mlx_get_data_addr(data->minimap.game_wall.texture, \
		&data->minimap.game_wall.info_texture.bpp, &data->minimap.game_wall.info_texture.line_len, &data->minimap.game_wall.info_texture.endian);
	data->player.dirX = 1;
	data->player.dirY = 0;
	data->player.planeX = 0;
	data->player.planeY = 0.66;
	data->camera.prev_x = 0;
	data->game.move_speed = 0.08;
	data->game.rotate_speed = 0.05;
}

void handle_render(t_data *data)
{
	mlx_hook(data->window.mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_hook(data->window.mlx_win, 6, 1L << 6, &handle_mouse_move, data);
	mlx_loop(data->window.mlx);
}

// north:
// 	data->player.dirX = 0;
// 	data->player.dirY = -1;
// 	data->player.planeX = 0.66;
// 	data->player.planeY = 0;

// sul:
// 	data->player.dirX = 0;
// 	data->player.dirY = 1;
// 	data->player.planeX = -0.66;
// 	data->player.planeY = 0;


// este:
// 		data->player.dirX = -1;
// 		data->player.dirY = 0;
// 		data->player.planeX = 0;
// 		data->player.planeY = -0.66;

// oeste:
// 		data->player.dirX = 1;
// 		data->player.dirY = 0;
// 		data->player.planeX = 0;
// 		data->player.planeY = 0.66;
