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
}

void	init_player(t_player *player)
{
	player->px = -1;
	player->py = -1;
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

void	set_rgb(t_data *data, t_rgb *rgb, char *line)
{
	char	**colors_array;
	int		r;
	int		g;
	int		b;

	colors_array = ft_split(line, ',');
	if (get_array_size(colors_array) != 3 || !is_digit_multiple(colors_array[0])
		|| !is_digit_multiple(colors_array[1])
		|| !is_digit_multiple(colors_array[2]))
	{
		free_array2d((void **)colors_array);
		error_handler2(data, RGB_ERROR);
	}
	r = ft_atoi(colors_array[0]);
	g = ft_atoi(colors_array[1]);
	b = ft_atoi(colors_array[2]);
	if (!is_rgb_range(r) || !is_rgb_range(g) || !is_rgb_range(b))
	{
		free_array2d((void **)colors_array);
		error_handler2(data, RGB_ERROR);
	}
	rgb->R = r;
	rgb->G = g;
	rgb->B = b;
	free_array2d((void **)colors_array);
}
