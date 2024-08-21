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
static int	clean_frames(t_data *data);

int	create_frames(t_data *data)
{
	int		frames;
	t_frame	*temp;
	t_frame	*tail;

	data->game.animation.frames = calloc(1, sizeof(t_frame));
	temp = data->game.animation.frames;
	temp->prev = NULL;
	frames = 1;
	while (frames < 39)
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
		frames++;
	}
	temp->next = NULL;
	return (1);
}

static int	clean_frames(t_data *data)
{
	t_frame	*tail;

	tail = data->game.animation.frames->next;
	while (data->game.animation.frames)
	{
		mlx_destroy_image(data->window.mlx, data->game.animation.frames->texture.info_texture.mlx_img);
		free(data->game.animation.frames);
		data->game.animation.frames = tail;
	}
	return (0);
}

static int	load_texture(t_data *data, t_frame *temp, int frames)
{
	char *path;

	path = create_path(frames);
	temp->texture.texture = mlx_xpm_file_to_image(data->window.mlx, path,
			&temp->texture.width, &temp->texture.height);
	if (temp->texture.texture == NULL)
	{
		free(temp);
		temp = NULL;
		return (0);
	}
	temp->texture.info_texture.data = mlx_get_data_addr(temp->texture.texture,
			&temp->texture.info_texture.bpp,
			&temp->texture.info_texture.line_len,
			&temp->texture.info_texture.endian);
	free(path);
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
