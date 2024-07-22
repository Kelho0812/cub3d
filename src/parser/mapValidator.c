/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:55:51 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 08:55:51 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	**map_parser(int fd, int i, int count, char *map_path);

#include "../../includes/cub3d.h"

void	parse_and_validate_map(char *map, t_data *data)
{
	int	fd;

	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		error_handler(data, WRONG_EXTENSION);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(data, OPEN_MAP_ERROR);
	init_map(&data->map);
	data->map.full_map_array = map_parser(fd, 0, 0, map);
	validate_map(data);
}

char	**map_parser(int fd, int i, int count, char *map_path)
{
	char	**lines;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit(1);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	lines = (char **)malloc(sizeof(char *) * (count + 1));
	lines[count] = NULL;
	close(fd);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	lines[i++] = NULL;
	return (lines);
}

void	validate_map(t_data *data)
{
	check_textures(data);
}
void	check_textures(t_data *data)
{
	int		i;
	char	**map_array;
	t_map	*map;

	map_array = data->map.full_map_array;
	map = &data->map;
	i = 0;
	while (map_array[i])
	{
		check_duplicate_textures(data, map_array[i]);
		if (is_NO(map_array[i]) && map->north_texture == NULL)
			copy_texture_path(map_array[i], map, NO);
		else if (is_SO(map_array[i]) && map->south_texture == NULL)
			copy_texture_path(map_array[i], map, SO);
		else if (is_WE(map_array[i]) && map->west_texture == NULL)
			copy_texture_path(map_array[i], map, WE);
		else if (is_EA(map_array[i]) && map->east_texture == NULL)
			copy_texture_path(map_array[i], map, EA);
		i++;
	}
}

void	check_duplicate_textures(t_data *data, char *line)
{
	t_map	*map;

	map = &data->map;
	if (is_NO(line) && map->north_texture != NULL)
		error_handler2(data, TEXTURE_ERROR);
	else if (is_SO(line) && map->south_texture != NULL)
		error_handler2(data, TEXTURE_ERROR);
	else if (is_WE(line) && map->west_texture != NULL)
		error_handler2(data, TEXTURE_ERROR);
	else if (is_EA(line) && map->east_texture != NULL)
		error_handler2(data, TEXTURE_ERROR);
}
