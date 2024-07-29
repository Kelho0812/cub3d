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
