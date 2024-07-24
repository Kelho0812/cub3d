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

void	copy_texture_path(t_map *map, char **line)
{
	if (line != NULL && line[0] != NULL && !ft_isdigit(line[0][0]))
	{
		if (!ft_strncmp(line[0], "NO", 2))
			map->north_texture = ft_strdup(line[1]);
		if (!ft_strncmp(line[0], "SO", 2))
			map->south_texture = ft_strdup(line[1]);
		if (!ft_strncmp(line[0], "WE", 2))
			map->west_texture = ft_strdup(line[1]);
		if (!ft_strncmp(line[0], "EA", 2))
			map->east_texture = ft_strdup(line[1]);
	}
}
