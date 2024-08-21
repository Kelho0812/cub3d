/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:31:33 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/21 09:31:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	render_scope(t_data *data);
static void	horizontal_scope(t_data *data, int x1);
static void	vertical_scope(t_data *data, int y1);

void	render_weapon(t_data *data)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	color;

	x1 = WIDTH / 2;
	y1 = HEIGHT - data->game.animation_torch.frames->texture.height;
	y = 0;
	while (y < data->game.animation_torch.frames->texture.height)
	{
		x = 0;
		while (x < data->game.animation_torch.frames->texture.width)
		{
			color = *(int *)(data->game.animation_torch.frames->texture.info_texture.data + y
					* data->game.animation_torch.frames->texture.info_texture.line_len + x
					* (data->game.animation_torch.frames->texture.info_texture.bpp / 8));
			if (color != -16777216)
				my_pixel_put(x1 + x, y1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
	data->game.animation_torch.frames = data->game.animation_torch.frames->next;
	render_scope(data);
}

static void	render_scope(t_data *data)
{
	int	x1;
	int	y1;

	x1 = WIDTH / 2 - 10;
	y1 = HEIGHT / 2 - 10;
	horizontal_scope(data, x1);
	vertical_scope(data, y1);
}

static void	horizontal_scope(t_data *data, int x1)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 3)
	{
		x = 1;
		while (x < 20)
		{
			color = 0xFFFFFF;
			my_pixel_put(x1 + x, HEIGHT / 2 - 1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
}

static void	vertical_scope(t_data *data, int y1)
{
	int	x;
	int	y;
	int	color;

	y = 1;
	while (y < 20)
	{
		x = 0;
		while (x < 3)
		{
			color = 0xFFFFFF;
			my_pixel_put(WIDTH / 2 - 1 + x, y1 + y, color, data->game.map_img);
			x++;
		}
		y++;
	}
}
