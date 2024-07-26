/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:31:58 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/23 10:19:27 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_handler(t_error error)
{
	if (error == WRONG_ARG_NUM)
	{
		printf("You should write: ./cub3d <map_relative_path>\n");
		printf("Example: ./cub3d ./maps/example.cub");
		exit(1);
	}
	else if (error == WRONG_EXTENSION)
	{
		printf("Error: Invalid map extension.\n");
		exit(1);
	}
	else if (error == OPEN_MAP_ERROR)
	{
		printf("Error: Could not open map.\n");
		exit(1);
	}
}

void	error_handler2(t_data *data, t_error error)
{
	if (error == TEXTURE_ERROR)
	{
		william_wallace(data);
		printf(RED "TEXTURE ERROR OH FILHA DA PUTA." RESET "\n");
		exit(1);
	}
	if (error == RGB_ERROR)
	{
		william_wallace(data);
		printf(RED "RGB ERROR OH CABRAO."RESET "\n");
		exit(1);
	}
}
