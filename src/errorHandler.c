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
		printf(RED "ERROR" RESET "\n");
		printf("You should write: ./cub3d <map_relative_path>\n");
		printf("Example: ./cub3d ./maps/example.cub");
		exit(1);
	}
	else if (error == WRONG_EXTENSION)
	{
		printf(RED "ERROR" RESET "\n");
		printf(RED "WRONG MAP EXTENSION. SHOULD BE .CUB" RESET "\n");
		exit(1);
	}
	else if (error == OPEN_MAP_ERROR)
	{
		printf(RED "ERROR" RESET "\n");
		printf(RED "CAN'T OPEN MAP FILE. MAKE SURE FILE EXISTS." RESET "\n");
		exit(1);
	}
	else if (error == EMPTY_MAP)
	{
		printf(RED "ERROR" RESET "\n");
		printf(RED "MAP SEEMS TO BE EMPTY" RESET "\n");
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
		printf(RED "ERROR" RESET "\n");
		printf(RED "ONE OF THE RGB VALUES IS INVALID" RESET "\n");
		exit(1);
	}
	if (error == WRONG_CHARS_MAP_ERROR)
	{
		william_wallace(data);
		printf(RED "WRONG CHARS NO MAPA ERROR OH BOI." RESET "\n");
		exit(1);
	}
	if (error == NOT_ENOUGH_ELEMENTS)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "WRONG ORDER OR NOT CORRECT NUM OF ELEMENTS ON MAP " RESET "\n");
		exit(1);
	}
}

void	error_handler3(t_data *data, t_error error)
{
	if (error == TEXTURE_ORDER)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "TEXTURES SEEMS TO HAVE WRONG ORDER OR AMOUNT OF ARGUMENTS" RESET "\n");
		exit(1);
	}
	if (error == INVALID_WORD)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "THERE IS AN INVALID WORD IN ONE OF THE LINES" RESET "\n");
		exit(1);
	}
	if (error == WRONG_FORMAT)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "THERE IS AN INVALID AMOUNT OF WORDS IN ONE OF THE ELEMENTS" RESET "\n");
		exit(1);
	}
	if (error == NOT_ENOUGH_ELEMENTS)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "NOT ENOUGH ELEMENTS ON MAP" RESET "\n");
		exit(1);
	}
}

void	error_handler4(t_data *data, t_error error)
{
	if (error == WRONG_IMAGE)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "CANNOT OPEN LE IMAGE" RESET "\n");
		exit(1);
	}
	if (error == MAP_HOLE)
	{
		william_wallace(data);
		printf(RED "ERROR" RESET "\n");
		printf(RED "HOLE IN DA MAP" RESET "\n");
		exit(1);
	}
	if (error == TEXTURE_OPEN_ERROR)
	{
		william_wallace(data);
		free(data->window.mlx);
		printf(RED "ERROR" RESET "\n");
		printf(RED "Textures couldn't be loaded." RESET "\n");
		exit(1);
	}
}
