/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:09:57 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 15:09:57 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_digit_multiple(char *digit)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(digit);
	while (i < len)
	{
		if (!ft_isdigit(digit[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_rgb_range(int RGB_Num)
{
	if (RGB_Num >= 0 && RGB_Num <= 255)
	{
		return (true);
	}
	return (false);
}

void	set_rgb(t_data *data, t_rgb *rgb, char **line)
{
	char	**colors_array;
	char	**line_real;
	int		j;

	j = 1;
	line_real = line;
	while (line_real[j] != NULL && line_real[j][0] != '\0')
	{
		colors_array = ft_split(line_real[j], ',');
		validate_number(data, colors_array, line);
		assign_rgb(rgb, colors_array);
		free_array2d((void **)colors_array);
		j++;
	}
	if ((rgb->r == -1 || rgb->g == -1 || rgb->b == -1))
	{
		free_array2d((void **)line);
		error_handler2(data, RGB_ERROR);
	}
}

void	validate_number(t_data *data, char **colors_array, char **line)
{
	int	i;

	i = 0;
	while (colors_array != NULL && colors_array[i] != NULL)
	{
		if (!is_digit_multiple(colors_array[i]))
		{
			free_array2d((void **)colors_array);
			free_array2d((void **)line);
			error_handler2(data, RGB_ERROR);
		}
		if (!is_rgb_range(ft_atoi(colors_array[i])))
		{
			free_array2d((void **)colors_array);
			free_array2d((void **)line);
			error_handler2(data, RGB_ERROR);
		}
		i++;
	}
}

void	assign_rgb(t_rgb *rgb, char **colors_array)
{
	int	i;

	i = 0;
	while (colors_array != NULL && colors_array[i] != NULL)
	{
		if (rgb->r == -1)
			rgb->r = ft_atoi(colors_array[i]);
		else if (rgb->g == -1)
			rgb->g = ft_atoi(colors_array[i]);
		else if (rgb->b == -1)
			rgb->b = ft_atoi(colors_array[i]);
		i++;
	}
}
