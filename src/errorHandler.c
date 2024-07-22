/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:31:58 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 10:32:08 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_handler(t_data *data, t_error error)
{
	if (error == WRONG_ARG_NUM)
	{
		(void)data;
		printf("You should write: ./cub3d <map_relative_path>\n");
		printf("Example: ./cub3d ./maps/example.cub");
		exit(1);
	}
	else if (error == WRONG_EXTENSION)
	{
		(void)data;
		printf("Error: Invalid map extension.\n");
		exit(1);
	}
	else if (error == OPEN_MAP_ERROR)
	{
		(void)data;
		printf("Error: Could not open map.\n");
		exit(1);
	}
}

void	error_handler2(t_data *data, t_error error)
{
	if (error == TEXTURE_ERROR)
	{
		free_map(data);
		printf("TEXTURE ERROR OH FILHA DA PUTA.\n");
		exit(1);
	}
}