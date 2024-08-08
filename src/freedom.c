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
	if (map->south_texture != NULL)
		free(map->south_texture);
	if (map->west_texture != NULL)
		free(map->west_texture);
	if (map->east_texture != NULL)
		free(map->east_texture);
}

void	free_array2d(void **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	william_wallace(t_data *data)
{
	free_array2d((void **)data->map.full_file_array);
	free_map(data);
}
