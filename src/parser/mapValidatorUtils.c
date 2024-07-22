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

#include "../../includes/cub3d.h"

bool	is_NO(char *map)
{
	if (map[0] == 'N' && map[1] == 'O')
		return (true);
	else
		return (false);
	;
}

bool	is_SO(char *map)
{
	if (map[0] == 'S' && map[1] == 'O')
		return (true);
	else
		return (false);
	;
}

bool	is_WE(char *map)
{
	if (map[0] == 'W' && map[1] == 'E')
		return (true);
	else
		return (false);
	;
}

bool	is_SE(char *map)
{
	if (map[0] == 'S' && map[1] == 'E')
		return (true);
	else
		return (false);
	;
}