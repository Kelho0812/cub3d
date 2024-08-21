/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:43:41 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/21 09:43:41 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	make_steps(t_data *data, t_dda_values *dda_values, t_rec_val *temp)
{
	if (data->dist.side_dist_x < data->dist.side_dist_y)
	{
		data->dist.side_dist_x += data->dist.delta_dist_x;
		dda_values->map_x += dda_values->step_x;
		temp->side = 0;
	}
	else
	{
		data->dist.side_dist_y += data->dist.delta_dist_y;
		dda_values->map_y += dda_values->step_y;
		temp->side = 1;
	}
}

void	door_case(t_data *data, t_dda_values *dda_v, t_rec_val *temp, int x)
{
	temp->map_x = dda_v->map_x;
	temp->map_y = dda_v->map_y;
	find_distance_to_wall(data, temp);
	execute_dda(dda_v, data, x);
}
