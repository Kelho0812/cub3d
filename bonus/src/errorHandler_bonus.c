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

#include "../includes/cub3d_bonus.h"

void	error_handler(t_error error)
{
	if (error == WRONG_ARG_NUM)
	{
		printf(RED "ERROR" RESET "\n");
		printf("You should write: ./cub3d <map_relative_path>\n");
		printf("Example: ./cub3d ./maps/example.cub");
		exit(1);
	}
	else if (error == WRONG_EXTENSION)
	{
		print_error("WRONG MAP EXTENSION. SHOULD BE .CUB");
		exit(1);
	}
	else if (error == OPEN_MAP_ERROR)
	{
		print_error("CAN'T OPEN MAP FILE. MAKE SURE FILE EXISTS.");
		exit(1);
	}
	else if (error == EMPTY_MAP)
	{
		print_error("MAP SEEMS TO BE EMPTY");
		exit(1);
	}
}

void	error_handler2(t_data *data, t_error error)
{
	if (error == RGB_ERROR)
	{
		william_wallace(data);
		print_error("ONE OF THE RGB VALUES IS INVALID");
		exit(1);
	}
	if (error == WRONG_CHARS_MAP_ERROR)
	{
		william_wallace(data);
		print_error("WRONG CHARS IN THE MAP.");
		exit(1);
	}
	if (error == NOT_ENOUGH_ELEMENTS)
	{
		william_wallace(data);
		print_error("WRONG ORDER/NUM OF ELEMENTS ON MAP");
		exit(1);
	}
}

void	error_handler3(t_data *data, t_error error)
{
	if (error == TEXTURE_ORDER)
	{
		william_wallace(data);
		print_error("TEXTURES HAVE WRONG ORDER/AMOUNT OF ARGUMENTS");
		exit(1);
	}
	if (error == INVALID_WORD)
	{
		william_wallace(data);
		print_error("THERE IS AN INVALID WORD IN ONE OF THE LINES");
		exit(1);
	}
	if (error == WRONG_FORMAT)
	{
		william_wallace(data);
		print_error("INVALID AMOUNT OF WORDS IN ONE OF THE ELEMENTS");
		exit(1);
	}
	if (error == NOT_ENOUGH_ELEMENTS)
	{
		william_wallace(data);
		print_error("NOT ENOUGH ELEMENTS ON MAP");
		exit(1);
	}
}

void	error_handler4(t_data *data, t_error error)
{
	if (error == MAP_HOLE)
	{
		william_wallace(data);
		free_map_array(data->map.full_map_array);
		print_error("HOLE IN DA MAP");
		exit(1);
	}
	if (error == TEXTURE_OPEN_ERROR)
	{
		william_wallace(data);
		free_map_array(data->map.full_map_array);
		destroy_images(data);
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
		print_error("Textures couldn't be loaded.");
		exit(1);
	}
}

void	print_error(char *error_msg)
{
	printf(RED "ERROR" RESET "\n");
	printf(RED "%s" RESET "\n", error_msg);
}
