/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:05:53 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/29 14:05:53 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (is_north(line[0]))
			map->north_texture = ft_strdup(line[1]);
		else if (is_south(line[0]))
			map->south_texture = ft_strdup(line[1]);
		else if (is_west(line[0]))
			map->west_texture = ft_strdup(line[1]);
		else if (is_east(line[0]))
			map->east_texture = ft_strdup(line[1]);
		else if (is_ceiling(line[0]))
			set_rgb(data, &map->ceiling_color, line[1]);
		else if (is_floor(line[0]))
			set_rgb(data, &map->floor_color, line[1]);
	}
}
