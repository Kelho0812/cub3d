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
	data->minimap.wall_texture = mlx_xpm_file_to_image(data->window.mlx, "./src/assets/wall.xpm", &data->minimap.width, &data->minimap.height);
	data->minimap.wall.data = mlx_get_data_addr(data->minimap.wall_texture, &data->minimap.wall.bpp, &data->minimap.wall.line_len, &data->minimap.wall.endian);
	data->minimap.floor_texture = mlx_xpm_file_to_image(data->window.mlx, "./src/assets/floor.xpm", &data->minimap.width, &data->minimap.height);
	data->minimap.floor.data = mlx_get_data_addr(data->minimap.floor_texture, &data->minimap.floor.bpp, &data->minimap.floor.line_len, &data->minimap.floor.endian);
	data->player.pa = 2.4;
	data->player.pdx = 0.0;
	data->player.pdy = 0.0;
}

void handle_render(t_data *data)
{
	mlx_hook(data->window.mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_loop(data->window.mlx);
}
