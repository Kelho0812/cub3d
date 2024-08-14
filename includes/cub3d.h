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
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define RESET "\033[0m"

# define WIDTH 1280
# define HEIGHT 1024

typedef struct s_dda_values
{
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					side;
	int					line_height;
}						t_dda_values;

typedef struct s_texture_values
{
	int					draw_start;
	int					draw_end;
	double				tex_pos;
	double				wall_x;
	double				step;
	int					tex_x;
	int					tex_y;
}						t_texture_values;

typedef struct s_img
{
	void				*mlx_img;
	char				*data;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_texture
{
	t_img				info_texture;
	void				*texture;
	int					height;
	int					width;
}						t_texture;

typedef struct s_ray
{
	double				ray_dir_x;
	double				ray_dir_y;
	double				camera_x;
}						t_ray;

typedef struct s_dist
{
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
}						t_dist;

typedef enum e_direction
{
	N,
	S,
	E,
	W
}						t_direction;

typedef struct s_player
{
	double				px;
	double				py;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	t_direction			direction;
}						t_player;

typedef struct s_map_dimensions
{
	int					rows;
	int					cols;
}						t_map_dimensions;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;
typedef struct s_map
{
	char				**full_file_array;
	char				**full_map_array;
	int					player_count;
	int					no_count;
	int					so_count;
	int					we_count;
	int					ea_count;
	int					f_count;
	int					c_count;
	char				*north_texture_path;
	char				*south_texture_path;
	char				*west_texture_path;
	char				*east_texture_path;
	t_rgb				ceiling_color;
	t_rgb				floor_color;
	t_map_dimensions	dimensions;
}						t_map;

typedef struct s_game
{
	double				rotate_speed;
	double				move_speed;
	double				time;
	double				oldtime;
	t_texture			north_texture;
	t_texture			south_texture;
	t_texture			east_texture;
	t_texture			west_texture;
	t_img				map_img;
}						t_game;

typedef struct s_window
{
	void				*mlx;
	void				*mlx_win;
}						t_window;

typedef struct s_data
{
	t_map				map;
	t_player			player;
	t_window			window;
	t_game				game;
	t_ray				rays;
	t_dist				dist;
	unsigned int		*buffer_background;
}						t_data;

// PARSER
void					parse_and_validate_map(char *map, t_data *data);
char					**map_parser(int fd, int i, int count, char *map_path);
void					validate_elements(t_data *data,
							char **line_words_array);
bool					is_digit_multiple(char *digit);
int						get_array_size(char **line_array);
void					verify_word_sequence(t_data *data,
							char **line_words_array);
void					validate_line_order(t_data *data,
							char **line_words_array);
void					free_map_array(char **map_array);
void					update_element_count(t_data *data, char *first_word);
void					check_wrong_chars(t_data *data, char **map_lines,
							int i);
int						check_map_start(t_data *data);
bool					is_rgb_range(int RGB_Num);
void					validate_and_copy_elements(t_data *data);
void					validate_and_copy_map(t_data *data);
void					copy_elements(t_data *data, char **line);
void					set_rgb(t_data *data, t_rgb *rgb, char **line);
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
void					validate_words(t_data *data, char **line_words_array);
bool					check_element_count(t_data *data);
bool					is_player(char *line);
void					validate_number(t_data *data, char **colors_array,
							char **line);
void					doublecheckelements(t_data *data);
void					assign_rgb(t_rgb *rgb, char **colors_array);
void					check_textures(t_data *data);

// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXTENSION,
	OPEN_MAP_ERROR,
	TEXTURE_ORDER,
	RGB_ERROR,
	WRONG_CHARS_MAP_ERROR,
	NOT_ENOUGH_ELEMENTS,
	EMPTY_MAP,
	INVALID_WORD,
	WRONG_FORMAT,
	MAP_HOLE,
	TEXTURE_OPEN_ERROR
}						t_error;

void					print_error(char *error_msg);
void					error_handler(t_error error);
void					error_handler2(t_data *data, t_error error);
void					error_handler3(t_data *data, t_error error);
void					error_handler4(t_data *data, t_error error);

// FREEDOM
void					william_wallace(t_data *data);
void					free_map(t_data *data);
void					free_array2d(void **pnts);
void					free_mapi(char **map, int rows);
void					destroy_images(t_data *data);

// other
void					init_data(t_data *data);
void					print_colored_map(char **map);

// game
void					play_game(t_data *data);
void					render_game(t_data *data);
void					open_window(t_data *data);

// game-renders
void					render_background(t_data *data);
void					draw_stripe(t_dda_values dda_values, int x,
							t_data *data);
void					my_pixel_put(int x, int y, int color, t_data *data);

// game-logic
void					init_values_dda(int x, t_dda_values *dda_values,
							t_data *data);
void					calculate_distances(t_dda_values *dda_values,
							t_data *data);
void					execute_dda(t_dda_values *dda_values, t_data *data);
void					find_distance_to_wall(t_dda_values *dda_values,
							t_data *data);

// game-handlers
int						handle_keypress(int keysym, t_data *data);
int						handle_close(t_data *data);
void					handle_render(t_data *data);

// game-utils
void					create_background_buffer(t_data *data);
void					init_game_values(t_data *data);
void					get_data_textures(t_data *data);
void					get_direction(t_data *data);

#endif
