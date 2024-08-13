/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:47:10 by jorteixe          #+#    #+#             */
/*   Updated: 2024/08/08 11:47:10 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->north_texture_path = NULL;
	map->south_texture_path = NULL;
	map->east_texture_path = NULL;
	map->west_texture_path = NULL;
	map->no_count = 0;
	map->so_count = 0;
	map->we_count = 0;
	map->ea_count = 0;
	map->c_count = 0;
	map->f_count = 0;
	map->ceiling_color.R = -1;
	map->ceiling_color.B = -1;
	map->ceiling_color.G = -1;
	map->floor_color.R = -1;
	map->floor_color.B = -1;
	map->floor_color.G = -1;
}

void	init_player(t_player *player)
{
	player->px = -1;
	player->py = -1;
	//#TODO Add Direction
}
