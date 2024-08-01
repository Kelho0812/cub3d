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
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define RED "\033[1;31m"
# define RESET "\033[0m"

# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK_SIZE 32
# define MINIMAP_SIZE 16
# define PLAYER_SIZE 10
# define PI 3.141592
# define P2 PI / 2
# define P3 3 * PI / 2
# define DEGRESS 0.017453 / 2

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_minimap
{
	t_img	wall;
	t_img	floor;
	void	*wall_texture;
	void	*floor_texture;
	int		height;
	int 	width;
}				t_minimap;

typedef struct s_ray
{
	float	atan;
	float	ntan;
	float	ry;
	float	rx;
	float	ystep;
	float	xstep;
    float   ra;
	int		mx;
	int		my;
}				t_ray;

typedef struct s_dist
{
    int		hx;
	int		hy;
	int		vx;
	int		vy;
	float	distH;
	float	distV;
	float	distT;
}   t_dist;

typedef struct s_player
{
	float					px;
	float					pdx;
	float					py;
	float					pdy;
	float					pa;
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
	t_img				map_img;
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
	t_minimap			minimap;
	t_ray				rays;
	t_dist				dist;
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
void					verifyWordSequence(t_data *data,
							char **line_words_array);
void					validateLineOrder(t_data *data,
							char **line_words_array);
void					updateElementCount(t_data *data, char *first_word);
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
void					validateWords(t_data *data, char **line_words_array);
bool					check_element_count(t_data *data);
bool					is_player(char *line);
void					validateNumber(t_data *data, char **colors_array, char **line);


// ERROR_HANDLERS
typedef enum e_error
{
	WRONG_ARG_NUM,
	WRONG_EXTENSION,
	OPEN_MAP_ERROR,
	TEXTURE_ERROR,
	TEXTURE_ORDER,
	RGB_ERROR,
	WRONG_CHARS_MAP_ERROR,
	NOT_ENOUGH_ELEMENTS,
	EMPTY_MAP,
	INVALID_WORD,
	WRONG_FORMAT
}						t_error;

void					error_handler(t_error error);
void					error_handler2(t_data *data, t_error error);
void					error_handler3(t_data *data, t_error error);

// FREEDOM
void					william_wallace(t_data *data);
void					free_map(t_data *data);
void					free_array2d(void **pnts);

// other
void					init_data(t_data *data);
void					init_player(t_player *player);
char					*ft_strdup_dif(const char *s, int size);
void					open_window(t_data *data);
void					print_colored_map(char **map);
void					render_minimap(t_data *data);
void 					handle_render(t_data *data);
void    				render_player(t_data *data);
void					draw_line(float x, float y, float x1, float y1, t_data *data);
void					my_pixel_put(int x, int y, int color, t_data *data);
void 					draw_fov(t_data *data);

//handlers

int 					handle_keypress(int keysym, t_data *data);
int						handle_close(t_data *data);

#endif
