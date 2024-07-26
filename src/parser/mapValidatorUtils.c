/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidatorUtils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:47:33 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 11:47:33 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#TODO Add errors when reading the texture path
//#TODO checkar com flood fill se consegue chegar a algum espaçol

#include "../../includes/cub3d.h"

bool	is_north(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "NO", i) != 0)
		return (false);
	else
		return (true);
}

bool	is_south(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "SO", i) != 0)
		return (false);
	else
		return (true);
}

bool	is_west(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "WE", i) != 0)
		return (false);
	else
		return (true);
}

bool	is_east(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "EA", i) != 0)
		return (false);
	else
		return (true);
}

bool	is_floor(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "F", i) != 0)
		return (false);
	else
		return (true);
}

bool	is_ceiling(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (ft_strncmp(line, "C", i) != 0)
		return (false);
	else
		return (true);
}

void	copy_elements(t_data *data, char **line)
{
	t_map	*map;

	map = &data->map;
	if (line != NULL && line[0] != NULL && !ft_isdigit(line[0][0]))
	{
		if (!ft_strncmp(line[0], "NO", 2))
			map->north_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "SO", 2))
			map->south_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "WE", 2))
			map->west_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "EA", 2))
			map->east_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "C", 2))
			set_RGB(data, &map->ceiling_color, line[1]);
		else if (!ft_strncmp(line[0], "F", 2))
			set_RGB(data, &map->floor_color, line[1]);
	}
}

void	set_RGB(t_data *data, t_rgb *rgb, char *line)
{
	char	**colors_array;
	int		R;
	int		G;
	int		B;

	colors_array = ft_split(line, ',');
	if (get_array_size(colors_array) != 3 || !is_digit_multiple(colors_array[0])
		|| !is_digit_multiple(colors_array[1])
		|| !is_digit_multiple(colors_array[2]))
	{
		free_array2d((void **)colors_array);
		error_handler2(data, RGB_ERROR);
	}
	R = ft_atoi(colors_array[0]);
	G = ft_atoi(colors_array[1]);
	B = ft_atoi(colors_array[2]);
	if (!is_RGB_range(R) || !is_RGB_range(G) || !is_RGB_range(B))
	{
		free_array2d((void **)colors_array);
		error_handler2(data, RGB_ERROR);
	}
	rgb->R = R;
	rgb->G = G;
	rgb->B = B;
	free_array2d((void **)colors_array);
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

bool	is_RGB_range(int RGB_Num)
{
	if (RGB_Num >= 0 && RGB_Num <= 255)
	{
		return (true);
	}
	return (false);
}