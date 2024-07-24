/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:54:21 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/23 10:23:58 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./getNextLine/getNextLine.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_rgb
{
	int		R;
	int		G;
	int		B;
}			t_rgb;
typedef struct s_map
{
	int		width;
	int		height;
	char	**full_map_array;
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_rgb	ceiling_color;
	t_rgb	floor_color;
}			t_map;
typedef struct s_data
{
	t_map	map;
}			t_data;

// PARSER
typedef enum e_coordinates
{
	NO,
	SO,
	WE,
	EA
}			t_coordinates;

void		parse_and_validate_map(char *map, t_data *data);
void		init_map(t_map *map);
char		**map_parser(int fd, int i, int count, char *map_path);
void		count_n_order(t_data *data, char **line_words_array);
void		textures_correct_format(t_data *data);
void		textures_duplicates_n_missing(t_data *data);
int			get_array_size(char **line_array);
void		check_word_order(t_data *data, char **line_words_array);
void		check_line_order(t_data *data, char **line_words_array);
void		increment_element_count(t_data *data, char *first_word);
void		validate_mapfile(t_data *data);
void		check_textures(t_data *data);
void		copy_texture_path(t_map *map, char **line);
bool		is_north(char *map);
bool		is_south(char *map);
bool		is_west(char *map);
bool		is_east(char *map);
bool		is_floor(char *line);
bool		is_ceiling(char *line);

// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXTENSION,
	OPEN_MAP_ERROR,
	TEXTURE_ERROR,

}			t_error;

void		error_handler(t_error error);
void		error_handler2(t_data *data, t_error error);

// FREEDOM
void		free_map(t_data *data);
void		free_array2d(void **pnts);

// other
void		init_data(t_data *data);

#endif
