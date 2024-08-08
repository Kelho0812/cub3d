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

void	validate_elements(t_data *data, char **line_words_array)
{
	validate_words(data, line_words_array);
	update_element_count(data, line_words_array[0]);
	verify_word_sequence(data, line_words_array);
	validate_line_order(data, line_words_array);
}

void	validate_words(t_data *data, char **line_words_array)
{
	char	*line;

	line = line_words_array[0];
	if (line == NULL || line[0] == '\0')
	{
		free_array2d((void **)line_words_array);
		error_handler3(data, INVALID_WORD);
	}
	else if (!is_player(line) && !is_ceiling(line) && !is_floor(line)
		&& !ft_isdigit(line[0]))
	{
		free_array2d((void **)line_words_array);
		error_handler3(data, INVALID_WORD);
	}
}

int	check_map_start(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**line_words_array;

	i = 0;
	line_words_array = NULL;
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

void	verify_word_sequence(t_data *data, char **line_array)
{
	if (line_array != NULL && line_array[0] != NULL && is_player(line_array[0])
		&& get_array_size(line_array) != 2)
	{
		free_array2d((void **)line_array);
		error_handler3(data, WRONG_FORMAT);
	}
	if (line_array != NULL && line_array[0] != NULL
		&& (is_ceiling(line_array[0]) || is_floor(line_array[0]))
		&& (get_array_size(line_array) < 2 || get_array_size(line_array) > 4))
	{
		free_array2d((void **)line_array);
		error_handler3(data, WRONG_FORMAT);
	}
}

void	validate_line_order(t_data *data, char **line_words_array)
{
	if (line_words_array != NULL && line_words_array[0] != NULL
		&& ft_isdigit(line_words_array[0][0]) && !check_element_count(data))
	{
		free_array2d((void **)line_words_array);
		error_handler2(data, NOT_ENOUGH_ELEMENTS);
	}
}
