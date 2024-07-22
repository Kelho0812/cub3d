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
void		parse_and_validate_map(char *map, t_data *data);

// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXT,
	OPEN_ERROR,

}			t_error;

void		error_handler(t_data *data, t_error error);

#endif
