/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValidator4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:09:34 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/29 14:09:34 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_colored_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		j = 0;
		while (map != NULL && map[i] != NULL && map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				printf("\033[0;31m%c\033[0m", map[i][j]);
			else if (map[i][j] == '0')
				printf("\033[0;32m%c\033[0m", map[i][j]);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				printf("\033[0;30m\033[47m%c\033[0m", map[i][j]);
			else
				printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	get_map_dimensions(char **map, int *rows, int *cols)
{
	int	i;
	int	len;

	i = 0;
	*rows = 0;
	*cols = 0;
	while (map[*rows] != NULL)
		(*rows)++;
	while (i < *rows)
	{
		len = ft_strlen(map[i]);
		if (len > *cols)
			*cols = len;
		i++;
	}
}

void	print_result_and_exit(bool can_reach_space_or_tab)
{
	if (can_reach_space_or_tab)
	{
		printf("A space or tab is reachable from the starting position.\n");
		exit(1);
	}
	else
	{
		printf("No space or tab is reachable from the starting position.\n");
	}
}

char	**allocate_and_initialize_map(int rows, int cols)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = (char **)malloc((rows + 2) * sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < rows + 2)
	{
		new_map[i] = (char *)malloc((cols + 2 + 1) * sizeof(char));
		j = 0;
		while (j < cols + 2)
		{
			new_map[i][j] = ' ';
			j++;
		}
		new_map[i][cols + 2] = '\0';
		i++;
	}
	return (new_map);
}

void	copy_original_map(char **new_map, char **map, int rows)
{
	int		i;
	size_t	z;

	i = 0;
	while (i < rows)
	{
		z = 0;
		while (z < ft_strlen(map[i]))
		{
			new_map[i + 1][z + 1] = map[i][z];
			z++;
		}
		i++;
	}
}
