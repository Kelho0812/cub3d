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

#include "../../includes/cub3d_bonus.h"

bool	is_valid_map_char(char c)
{
	return (ft_strchr("0123456", c));
}

bool	is_valid_char(char c)
{
	return (is_valid_map_char(c) || is_player_char(c) || c == ' ' || c == '\t');
}

void	check_wrong_chars(t_data *data, char **map_lines, int i)
{
	t_norminetingz	n;

	n.map_end = false;
	n.wowzers = i;
	n.player_count = 0;
	while (map_lines[i] != NULL)
	{
		n.j = -1;
		while (map_lines[i][++n.j] != '\0')
		{
			if (n.map_end == true)
			{
				error_handler2(data, WRONG_CHARS_MAP_ERROR);
			}
			if (is_player_char(map_lines[i][n.j]))
				handle_player_char(data, i, &n);
			else if (!is_valid_char(map_lines[i][n.j]))
				error_handler2(data, WRONG_CHARS_MAP_ERROR);
		}
		if (n.j == 0 && map_lines[i][n.j] == '\0')
			n.map_end = true;
		i++;
	}
	if (n.player_count != 1)
		error_handler2(data, WRONG_CHARS_MAP_ERROR);
}

void	handle_player_char(t_data *data, int i, t_norminetingz *n)
{
	if (n->player_count == 0)
	{
		data->player.px = n->j;
		data->player.py = i - n->wowzers;
		if (data->map.full_file_array[i][n->j] == 'N')
			data->player.direction = N;
		else if (data->map.full_file_array[i][n->j] == 'S')
			data->player.direction = S;
		else if (data->map.full_file_array[i][n->j] == 'E')
			data->player.direction = E;
		else if (data->map.full_file_array[i][n->j] == 'W')
			data->player.direction = W;
		(n->player_count)++;
	}
	else
		error_handler2(data, WRONG_CHARS_MAP_ERROR);
}

bool	is_player(char *line)
{
	if (is_north(line) || is_south(line) || is_west(line) || is_east(line))
		return (true);
	else
		return (false);
}
