/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:09:57 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 15:09:57 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->no_count = 0;
	map->so_count = 0;
	map->we_count = 0;
	map->ea_count = 0;
	map->c_count = 0;
	map->f_count = 0;
	map->ceiling_color.R = -1;
	map->ceiling_color.B = -1;
	map->ceiling_color.G = -1;
	map->floor_color.R = -1;
	map->floor_color.B = -1;
	map->floor_color.G = -1;
}

void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
}

bool	is_digit_multiple(char *digit)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(digit);
	while (i < len)
	{
		if (!ft_isdigit(digit[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_rgb_range(int RGB_Num)
{
	if (RGB_Num >= 0 && RGB_Num <= 255)
	{
		return (true);
	}
	return (false);
}

void	set_rgb(t_data *data, t_rgb *rgb, char **line)
{
	char	**colors_array;
	char	*line_real;
	int		i;

	i = 0;
	line_real = line[1];
	colors_array = ft_split(line_real, ',');
	validateNumber(data, colors_array, line);
	while (colors_array != NULL && colors_array[i] != NULL)
	{
		if (rgb->R == -1)
		{
			rgb->R = ft_atoi(colors_array[i]);
		}
		else if (rgb->G == -1)
		{
			rgb->G = ft_atoi(colors_array[i]);
		}
		else if (rgb->B == -1)
		{
			rgb->B = ft_atoi(colors_array[i]);
		}
		i++;
	}
	free_array2d((void **)colors_array);
}

void	validateNumber(t_data *data, char **colors_array, char **line)
{
	int	i;

	i = 0;
	while (colors_array != NULL && colors_array[i] != NULL)
	{
		if (!is_digit_multiple(colors_array[i]))
		{
			free_array2d((void **)colors_array);
			free_array2d((void **)line);
			error_handler2(data, RGB_ERROR);
		}
		if (!is_rgb_range(ft_atoi(colors_array[i])))
		{
			free_array2d((void **)colors_array);
			free_array2d((void **)line);
			error_handler2(data, RGB_ERROR);
		}
		i++;
	}
}
