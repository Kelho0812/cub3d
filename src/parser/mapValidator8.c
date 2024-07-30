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

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || is_player_char(c) || c == ' ' || c == '\t');
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
			if (is_player_char(map_lines[i][j]))
				handle_player_char(data, &player_count, i, j, wowzers);
			else if (!is_valid_char(map_lines[i][j]))
				error_handler2(data, WRONG_CHARS_MAP_ERROR);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		error_handler2(data, WRONG_CHARS_MAP_ERROR);
}

void	handle_player_char(t_data *data, int *player_count, int i, int j,
		int wowzers)
{
	if (*player_count == 0)
	{
		data->player.x = j;
		data->player.y = i - wowzers;
		(*player_count)++;
	}
	else
	{
		error_handler2(data, WRONG_CHARS_MAP_ERROR);
	}
}

bool	is_player(char *line)
{
	if (is_north(line) || is_south(line) || is_west(line) || is_east(line))
		return true;
	else
		return false;
}