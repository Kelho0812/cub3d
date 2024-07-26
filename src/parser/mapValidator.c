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

void	validate_and_copy_elements(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	while (data->map.full_file_array[i] != NULL)
	{
		trimmed_line = ft_strtrim(data->map.full_file_array[i], " \t");
		line_words_array = ft_split(trimmed_line, ' ');
		validate_elements(data, line_words_array);
		copy_elements(data, line_words_array);
		free(trimmed_line);
		free_array2d((void **)(line_words_array));
		i++;
	}
}

void	validate_and_copy_map(t_data *data)
{
	int		i;
	char	**map_array;
	char	**new_map_array;

	map_array = data->map.full_file_array;
	i = check_map_start(data);
	check_wrong_chars(data, map_array, i);
	new_map_array = copy_map_from_index(data, i);
	i = 0;
	while (new_map_array != NULL && new_map_array[i] != NULL)
	{
		printf("%s\n", new_map_array[i]);
		i++;
	}
	check_path(new_map_array, data);
}

void	check_wrong_chars(t_data *data, char **map_lines, int i)
{
	int	j;
	int	wowzers;
	int	player_count;

	wowzers = i;
	player_count = 0;
	while (map_lines[i] != NULL)
	{
		j = 0;
		while (map_lines[i][j] != '\0')
		{
			if ((map_lines[i][j] == 'N' || map_lines[i][j] == 'S'
					|| map_lines[i][j] == 'W' || map_lines[i][j] == 'E')
				&& player_count == 0)
			{
				data->player.x = j;
				data->player.y = i - wowzers;
				player_count++;
			}
			else if ((map_lines[i][j] == 'N' || map_lines[i][j] == 'S'
					|| map_lines[i][j] == 'W' || map_lines[i][j] == 'E')
				&& player_count != 0)
				error_handler2(data, WRONG_CHARS_MAP_ERROR);
			if (map_lines[i][j] != '0' && map_lines[i][j] != '1'
				&& map_lines[i][j] != 'N' && map_lines[i][j] != 'S'
				&& map_lines[i][j] != 'W' && map_lines[i][j] != 'E'
				&& map_lines[i][j] != ' ' && map_lines[i][j] != '\t')
			{
				error_handler2(data, WRONG_CHARS_MAP_ERROR);
			}
			j++;
		}
		i++;
	}
}

int	check_map_start(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	while (data->map.full_file_array[i] != NULL)
	{
		trimmed_line = ft_strtrim(data->map.full_file_array[i], " \t");
		line_words_array = ft_split(trimmed_line, ' ');
		if (line_words_array[0] != NULL && line_words_array[0][0] != '\0')
		{
			if (ft_isdigit(line_words_array[0][0]))
			{
				free_array2d((void **)line_words_array);
				return (i);
			}
		}
		i++;
	}
	free_array2d((void **)line_words_array);
	return (0);
}

void	validate_elements(t_data *data, char **line_words_array)
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

void	check_path(char **map, t_data *data)
{
	bool	can_reach_space_or_tab;
	int		rows;
	int		cols;
	int		len;
	int		i;

	i = 0;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	cols = 0;
	while (i < rows)
	{
		len = ft_strlen(map[i]);
		if (len > cols)
			cols = len;
		i++;
	}
	can_reach_space_or_tab = dfs(map, data->player.y, data->player.x, rows,
			cols);
	if (can_reach_space_or_tab)
		printf("A space or tab is reachable from the starting position.\n");
	else
		printf("No space or tab is reachable from the starting position.\n");
	free_array2d((void **)map);
}

char	**copy_map_from_index(t_data *data, int start_index)
{
	char	**map_array;
	char	**new_map_array;

	int i, num_lines;
	map_array = data->map.full_file_array;
	num_lines = 0;
	while (map_array[start_index + num_lines] != NULL)
	{
		num_lines++;
	}
	new_map_array = (char **)malloc((num_lines + 1) * sizeof(char *));
	// if (new_map_array == NULL)
	for (i = 0; i < num_lines; i++)
	{
		new_map_array[i] = ft_strdup(map_array[start_index + i]);
		// if (new_map_array[i] == NULL)
	}
	new_map_array[num_lines] = NULL;
	return (new_map_array);
}

bool	dfs(char **map, int x, int y, int rows, int cols)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return (false);
	if (map == NULL || map[x] == NULL)
		return (false);
	if (map[x][y] == '1' || map[x][y] == 'V')
		return (false);
	if (map[x][y] == ' ' || map[x][y] == '\t')
		return (true);
	map[x][y] = 'V';
	if (dfs(map, x - 1, y, rows, cols) || dfs(map, x + 1, y, rows, cols)
		|| dfs(map, x, y - 1, rows, cols) || dfs(map, x, y + 1, rows, cols))
	{
		return (true);
	}
	return (false);
}
