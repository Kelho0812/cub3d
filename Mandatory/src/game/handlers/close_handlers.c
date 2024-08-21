/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:34:32 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 15:34:32 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_close(t_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->window.mlx, data->window.mlx_win);
	mlx_destroy_display(data->window.mlx);
	free(data->window.mlx);
	free_map_array(data->map.full_map_array);
	william_wallace(data);
	free(data->buffer_background);
	exit(0);
}
