/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:18:21 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/29 14:18:21 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_start(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	while (data->map.full_file_array[i] != NULL)
	{
		trimmed_line = ft_strtrim(data->map.full_file_array[i], " \t");
		line_words_array = ft_split(trimmed_line, ' ');
		free(trimmed_line);
		if (line_words_array[0] != NULL && line_words_array[0][0] != '\0')
		{
			if (ft_isdigit(line_words_array[0][0]))
			{
				free_array2d((void **)line_words_array);
				return (i);
			}
		}
		free_array2d((void **)line_words_array);
		i++;
	}
	return (0);
}

void	validate_elements(t_data *data, char **line_words_array)
{
	increment_element_count(data, line_words_array[0]);
	check_word_order(data, line_words_array);
	check_line_order(data, line_words_array);
}

void	check_word_order(t_data *data, char **line_array)
{
	if (line_array != NULL && line_array[0] != NULL
		&& !ft_isdigit(line_array[0][0]) && (is_player(line_array[0])) && (get_array_size(line_array) != 2))
		error_handler2(data, TEXTURE_ERROR);
}

void	check_line_order(t_data *data, char **line_words_array)
{
	if (line_words_array != NULL && line_words_array[0] != NULL
		&& ft_isdigit(line_words_array[0][0]) && (data->map.no_count != 1
			|| data->map.so_count != 1 || data->map.we_count != 1
			|| data->map.ea_count != 1 || data->map.c_count != 1
			|| data->map.f_count != 1))
		error_handler2(data, TEXTURE_ERROR);
}
