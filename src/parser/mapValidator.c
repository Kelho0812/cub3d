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
	data->map.full_file_array = map_parser(fd, 0, 0, map);
	validate_and_copy_elements(data);
	validate_and_copy_map(data);
	data->player.px *= BLOCK_SIZE;
    data->player.py *= BLOCK_SIZE;
}

char	**map_parser(int fd, int i, int count, char *map_path)
{
	char	**lines;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_handler(EMPTY_MAP);
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

void	validate_and_copy_elements(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	while (data->map.full_file_array[i] != NULL)
	{
		trimmed_line = ft_strtrim(data->map.full_file_array[i], " \t");
		if (data->map.full_file_array[i][0] != '\0')
		{
			line_words_array = ft_split(trimmed_line, ' ');
			if (line_words_array != NULL && line_words_array[0] != NULL
				&& line_words_array[0][0] != '\0')
			{
				free(trimmed_line);
				validate_elements(data, line_words_array);
				copy_elements(data, line_words_array);
				free_array2d((void **)(line_words_array));
			}
		}
		i++;
	}
	if ((data->map.no_count != 1 || data->map.so_count != 1
			|| data->map.we_count != 1 || data->map.ea_count != 1
			|| data->map.c_count != 1 || data->map.f_count != 1))
	{
		error_handler2(data, NOT_ENOUGH_ELEMENTS);
	}
}

bool	check_element_count(t_data *data)
{
	if ((data->map.no_count != 1 || data->map.so_count != 1
			|| data->map.we_count != 1 || data->map.ea_count != 1
			|| data->map.c_count != 1 || data->map.f_count != 1))
		return (false);
	else
		return (true);
}

void	validate_and_copy_map(t_data *data)
{
	int		i;
	char	**map_array;

	map_array = data->map.full_file_array;
	i = check_map_start(data);
	check_wrong_chars(data, map_array, i);
	data->map.full_map_array = copy_map_from_index(data, i);
	print_colored_map(data->map.full_map_array);
	check_path(data->map.full_map_array, data);
}

bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
