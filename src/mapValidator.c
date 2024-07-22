/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:55:51 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 08:55:51 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	**map_parser(int fd, int i, int count, char *map_path);

#include "../includes/cub3d.h"

void	parse_and_validate_map(char *map, t_data *data)
{
	int	fd;

	(void)data;
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		error_handler(data, WRONG_EXT);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(data, OPEN_ERROR);
	data->map.full_map_array = map_parser(fd, 0, 0, map);
}

char	**map_parser(int fd, int i, int count, char *map_path)
{
	char	**lines;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit(1);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	lines = (char **)malloc(sizeof(char *) * (count + 1));
	lines[count] = NULL;
	close(fd);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	return (lines);
}
