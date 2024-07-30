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
# include "./minilibx-linux/mlx.h"

# define RED "\033[1;31m"
# define RESET "\033[0m"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_player
{
	int					x;
	int					y;
}						t_player;

typedef struct s_map_dimensions
{
	int					rows;
	int					cols;
}						t_map_dimensions;

typedef struct s_rgb
{
	int					R;
	int					G;
	int					B;
}						t_rgb;
typedef struct s_map
{
	int					width;
	int					height;
	char				**full_file_array;
	char				**full_map_array;
	int					player_count;
	int					no_count;
	int					so_count;
	int					we_count;
	int					ea_count;
	int					f_count;
	int					c_count;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	t_rgb				ceiling_color;
	t_rgb				floor_color;
	t_map_dimensions	dimensions;
}						t_map;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
}				t_window;

typedef struct s_data
{
	t_map				map;
	t_player			player;
	t_window			window;
}						t_data;

// PARSER
void					parse_and_validate_map(char *map, t_data *data);
void					init_map(t_map *map);
char					**map_parser(int fd, int i, int count, char *map_path);
void					validate_elements(t_data *data,
							char **line_words_array);
void					textures_correct_format(t_data *data);
bool					is_digit_multiple(char *digit);
int						get_array_size(char **line_array);
void					check_word_order(t_data *data, char **line_words_array);
void					check_line_order(t_data *data, char **line_words_array);
void					increment_element_count(t_data *data, char *first_word);
void					check_wrong_chars(t_data *data, char **map_lines,
							int i);
int						check_map_start(t_data *data);
bool					is_rgb_range(int RGB_Num);
void					validate_and_copy_elements(t_data *data);
void					validate_and_copy_map(t_data *data);
void					copy_elements(t_data *data, char **line);
void					set_rgb(t_data *data, t_rgb *rgb, char *line);
bool					is_north(char *map);
bool					is_south(char *map);
bool					is_west(char *map);
bool					is_east(char *map);
bool					is_floor(char *line);
bool					is_ceiling(char *line);
bool					dfs(char **map, int x, int y);
void					check_path(char **map, t_data *data);
char					**copy_map_from_index(t_data *data, int start_index);
char					**duplicate_map_with_border(char **map, int rows,
							int cols);
bool					is_player_char(char c);
bool					is_valid_char(char c);
void					handle_player_char(t_data *data, int *player_count,
							int i, int j, int wowzers);
void					get_map_dimensions(char **map, int *rows, int *cols);
void					print_result_and_exit(bool can_reach_space_or_tab);
char					**allocate_and_initialize_map(int rows, int cols);
void					copy_original_map(char **new_map, char **map, int rows);

bool					is_player(char *line);

// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXTENSION,
	OPEN_MAP_ERROR,
	TEXTURE_ERROR,
	RGB_ERROR,
	WRONG_CHARS_MAP_ERROR

}						t_error;

void					error_handler(t_error error);
void					error_handler2(t_data *data, t_error error);

// FREEDOM
void					william_wallace(t_data *data);
void					free_map(t_data *data);
void					free_array2d(void **pnts);

// other
void					init_data(t_data *data);
void					init_player(t_player *player);
void					open_window(t_data *data);
void					print_colored_map(char **map);
void					render_minimap(t_data *data);
void 					handle_render(t_data *data);

#endif
