/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:16:05 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/29 14:16:09 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

char	**duplicate_map_with_border(char **map, int rows, int cols)
{
	char	**new_map;

	new_map = allocate_and_initialize_map(rows, cols);
	if (new_map == NULL)
		return (NULL);
	copy_original_map(new_map, map, rows);
	return (new_map);
}
