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
	init_game_values(&data);
	render_map(&data);
	handle_render(&data);
	mlx_destroy_window(data.window.mlx, data.window.mlx_win);
	mlx_destroy_display(data.window.mlx);
	free(data.window.mlx);
	william_wallace(&data);
	free_map_array(data.map.full_map_array);
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
	check_textures(data);
	get_data_textures(data);
	get_direction(data);
	data->window.mlx_win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT,
			"Cub3d - MegaBosses");
}

void	handle_render(t_data *data)
{
	mlx_hook(data->window.mlx_win, KeyPress, KeyPressMask, &handle_keypress,
		data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close,
		data);
	mlx_hook(data->window.mlx_win, DestroyNotify, NoEventMask, &handle_close,
		data);
	mlx_loop(data->window.mlx);
}
