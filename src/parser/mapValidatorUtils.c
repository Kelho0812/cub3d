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

bool	is_north(char *line)
{
	if (line != NULL && line[0] != '\0')
	{
		if (ft_strlen(line) != 2)
			return (false);
		if (ft_strncmp(line, "NO", 2) != 0)
			return (false);
		else
			return (true);
	}
	return (false);
}

bool	is_south(char *line)
{
	if (ft_strlen(line) != 2)
		return (false);
	if (ft_strncmp(line, "SO", 2) != 0)
		return (false);
	else
		return (true);
}

bool	is_west(char *line)
{
	if (ft_strlen(line) != 2)
		return (false);
	if (ft_strncmp(line, "WE", 2) != 0)
		return (false);
	else
		return (true);
}

bool	is_east(char *line)
{
	if (ft_strlen(line) != 2)
		return (false);
	if (ft_strncmp(line, "EA", 2) != 0)
		return (false);
	else
		return (true);
}

bool	is_floor(char *line)
{
	if (ft_strlen(line) != 1)
		return (false);
	if (ft_strncmp(line, "F", 1) != 0)
		return (false);
	else
		return (true);
}
