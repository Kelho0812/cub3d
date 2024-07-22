/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:51:50 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 08:47:53 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("You should write: %s <map_relative_path>\n", argv[0]);
		printf("Example: ./cub3d map.cub");
		return (1);
	}
	parse_n_validate_map(argv[1], &data);
	return (0);
}
