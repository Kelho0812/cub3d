/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:54:21 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/19 18:54:43 by jorteixe         ###   ########.fr       */
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
void		check_duplicates(t_data *data);
void		validate_map(t_data *data);
void		check_textures(t_data *data);
void		copy_texture_path(char *line, t_map *map, t_coordinates c);
bool		is_NO(char *map);
bool		is_SO(char *map);
bool		is_WE(char *map);
bool		is_EA(char *map);

// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXTENSION,
	OPEN_MAP_ERROR,
	TEXTURE_ERROR,

}			t_error;

void		error_handler(t_data *data, t_error error);
void		error_handler2(t_data *data, t_error error);

// FREEDOM
void		free_map(t_data *data);

#endif
