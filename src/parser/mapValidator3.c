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
		if (!ft_strncmp(line[0], "NO", 2))
			map->north_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "SO", 2))
			map->south_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "WE", 2))
			map->west_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "EA", 2))
			map->east_texture = ft_strdup(line[1]);
		else if (!ft_strncmp(line[0], "C", 2))
			set_rgb(data, &map->ceiling_color, line[1]);
		else if (!ft_strncmp(line[0], "F", 2))
			set_rgb(data, &map->floor_color, line[1]);
	}
}
