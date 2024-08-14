/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:18:21 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/29 14:18:21 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	update_element_count(t_data *data, char *first_word)
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
	char	**spaced_map;
	bool	can_reach_space_or_tab;
	int		rows;
	int		cols;

	get_map_dimensions(map, &rows, &cols);
	spaced_map = duplicate_map_with_border(map, rows, cols);
	can_reach_space_or_tab = dfs(spaced_map, data->player.py + 1,
			data->player.px + 1);
	free_mapi(spaced_map, rows);
	if (can_reach_space_or_tab)
		error_handler4(data, MAP_HOLE);
}

char	**copy_map_from_index(t_data *data, int start_index)
{
	char	**map_array;
	char	**new_map_array;
	int		i;
	int		num_lines;

	map_array = data->map.full_file_array;
	num_lines = 0;
	i = 0;
	while (map_array[start_index + num_lines] != NULL)
	{
		num_lines++;
	}
	new_map_array = (char **)calloc((num_lines + 1), sizeof(char *));
	while (i < num_lines)
	{
		new_map_array[i] = ft_strdup(map_array[start_index + i]);
		i++;
	}
	new_map_array[num_lines] = NULL;
	return (new_map_array);
}

bool	dfs(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return (false);
	if (map[x][y] == ' ' || map[x][y] == '\t')
		return (true);
	map[x][y] = 'V';
	if (dfs(map, x - 1, y) || dfs(map, x + 1, y) || dfs(map, x, y - 1)
		|| dfs(map, x, y + 1))
	{
		return (true);
	}
	return (false);
}
