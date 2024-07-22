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

#include "../../includes/cub3d.h"

bool	is_NO(char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (true);
	else
		return (false);
}

bool	is_SO(char *line)
{
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (true);
	else
		return (false);
	;
}

bool	is_WE(char *line)
{
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (true);
	else
		return (false);
	;
}

bool	is_EA(char *line)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (true);
	else
		return (false);
	;
}

void	copy_texture_path(char *line, t_map *map, t_coordinates c)
{
	int	i;

	i = 0;
	while (line[i + 2] == ' ')
		i++;
	if (c == NO)
		map->north_texture = ft_strdup(line + 2 + i);
	if (c == SO)
		map->south_texture = ft_strdup(line + 2 + i);
	if (c == WE)
		map->west_texture = ft_strdup(line + 2 + i);
	if (c == EA)
		map->east_texture = ft_strdup(line + 2 + i);
}
