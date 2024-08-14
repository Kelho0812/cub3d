/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:46:27 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/14 14:46:27 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	create_background_buffer(t_data *data)
{
	int	x;
	int	y;
	int	celling;
	int	floor;

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

void	init_game_values(t_data *data)
{
	data->player.px += 0.5;
	data->player.py += 0.5;
	data->game.move_speed = 0.08;
	data->game.rotate_speed = 0.05;
	create_background_buffer(data);
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
