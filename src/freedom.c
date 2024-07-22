/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:42:10 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 15:42:10 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_data *data)
{
	t_map	*map;
	map = &data->map;
	if (map->north_texture != NULL)
		free(map->north_texture);
	else if (map->south_texture != NULL)
		free(map->south_texture);
	else if (map->west_texture != NULL)
		free(map->west_texture);
	else if (map->east_texture != NULL)
		free(map->east_texture);
}
