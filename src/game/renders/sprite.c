/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:30:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/17 12:30:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static char	*create_path(int frames);
static int	load_texture(t_data *data, t_frame *temp, int frames);

int	create_frames(t_data *data)
{
	int		frames;
	t_frame	*temp;
	t_frame	*tail;

	data->game.animation.frames = calloc(1, sizeof(t_frame));
	temp = data->game.animation.frames;
	data->game.animation.start = temp;
	temp->prev = NULL;
	frames = 0;
	while (++frames < 39)
	{
		if (!load_texture(data, temp, frames))
			return (clean_frames(data));
		if (frames + 1 != 39)
		{
			temp->next = calloc(1, sizeof(t_frame));
			tail = temp;
			temp = temp->next;
		}
		if (frames != 1)
			temp->prev = tail;
	}
	data->game.animation.end = temp;
	temp->next = NULL;
	return (1);
}

int	clean_frames(t_data *data)
{
	t_frame	*tail;
	t_frame	*temp;

	if (data->game.door_status == 2)
		tail = data->game.animation.end;
	else
		tail = data->game.animation.start;
	while (tail)
	{
		if (data->game.door_status == 2)
			temp = tail->prev;
		else
			temp = tail->next;
		mlx_destroy_image(data->window.mlx, tail->texture.texture);
		free(tail);
		tail = temp;
	}
	return (0);
}

static int	load_texture(t_data *data, t_frame *temp, int frames)
{
	char	*path;
	t_frame	*prev;

	path = create_path(frames);
	temp->texture.texture = mlx_xpm_file_to_image(data->window.mlx, path,
			&temp->texture.width, &temp->texture.height);
	free(path);
	if (temp->texture.texture == NULL)
	{
		prev = temp->prev;
		free(temp);
		if (prev)
			prev->next = NULL;
		return (0);
	}
	temp->texture.info.data = mlx_get_data_addr(temp->texture.texture,
			&temp->texture.info.bpp,
			&temp->texture.info.line_len,
			&temp->texture.info.endian);
	return (1);
}

static char	*create_path(int frames)
{
	char	*path;
	char	*temp;
	char	*num;

	num = ft_itoa(frames);
	temp = ft_strjoin("./textures/animation", num);
	path = ft_strjoin(temp, ".xpm");
	free(num);
	free(temp);
	return (path);
}
