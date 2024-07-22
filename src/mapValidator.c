/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:55:51 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 08:55:51 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_and_validate_map(char *map, t_data *data)
{
	int	fd;

	(void)data;
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		error_handler(data, WRONG_EXT);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(data, OPEN_ERROR);
}
