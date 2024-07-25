/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:55:51 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/23 10:32:14 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_and_validate_map(char *map, t_data *data)
{
	int	fd;

	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		error_handler(WRONG_EXTENSION);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(OPEN_MAP_ERROR);
	data->map.full_map_array = map_parser(fd, 0, 0, map);
	validate_mapfile(data);
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

void	validate_mapfile(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	while (data->map.full_map_array[i] != NULL)
	{
		trimmed_line = ft_strtrim(data->map.full_map_array[i], " \t");
		line_words_array = ft_split(trimmed_line, ' ');
		count_n_order(data, line_words_array);
		free(trimmed_line);
		free_array2d((void **)(line_words_array));
		i++;
	}
}

void	count_n_order(t_data *data, char **line_words_array)
{
	increment_element_count(data, line_words_array[0]);
	check_word_order(data, line_words_array);
	check_line_order(data, line_words_array);
}
void	check_word_order(t_data *data, char **line_array)
{
	if (line_array != NULL && line_array[0] != NULL
		&& !ft_isdigit(line_array[0][0]) && (get_array_size(line_array) != 2))
		error_handler2(data, TEXTURE_ERROR);
	copy_texture_path(data, line_array);
}

void	check_line_order(t_data *data, char **line_words_array)
{
	if (line_words_array != NULL && line_words_array[0] != NULL
		&& ft_isdigit(line_words_array[0][0]) && (data->map.no_count != 1
			|| data->map.so_count != 1 || data->map.we_count != 1
			|| data->map.ea_count != 1 || data->map.c_count != 1
			|| data->map.f_count != 1))
		error_handler2(data, TEXTURE_ERROR);
}

int	get_array_size(char **line_array)
{
	int	i;

	i = 0;
	while (line_array[i])
	{
		i++;
	}
	return (i);
}

void	increment_element_count(t_data *data, char *first_word)
{
	if (first_word)
	{
		if (is_north(first_word))
			data->map.no_count++;
		else if (is_south(first_word))
			data->map.so_count++;
		else if (is_west(first_word))
			data->map.we_count++;
		else if (is_east(first_word))
			data->map.ea_count++;
		else if (is_east(first_word))
			data->map.ea_count++;
		else if (is_east(first_word))
			data->map.ea_count++;
		else if (is_ceiling(first_word))
			data->map.c_count++;
		else if (is_floor(first_word))
			data->map.f_count++;
	}
}

void	textures_duplicates_n_missing(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.full_map_array[i] != NULL)
	{
		data->map.full_map_array[i] = ft_strtrim(data->map.full_map_array[i],
				" \t");
		if (is_north(data->map.full_map_array[i]))
			data->map.no_count++;
		else if (is_south(data->map.full_map_array[i]))
			data->map.so_count++;
		else if (is_west(data->map.full_map_array[i]))
			data->map.we_count++;
		else if (is_east(data->map.full_map_array[i]))
			data->map.ea_count++;
		i++;
	}
	if (data->map.no_count != 1 || data->map.so_count != 1
		|| data->map.we_count != 1 || data->map.ea_count != 1)
	{
		error_handler2(data, TEXTURE_ERROR);
	}
}
