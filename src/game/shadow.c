/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:38:55 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/21 13:38:55 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	shadow_floor(int color, int y)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) + (y * 0.3);
	g = ((color >> 8) & 0xFF) + (y * 0.3);
	b = (color & 0xFF) + (y * 0.3);
	return ((r << 16) | (g << 8) | b);
}

int	shadow_celling(int color, int y)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) - (y * 0.2);
	g = ((color >> 8) & 0xFF) - (y * 0.2);
	b = (color & 0xFF) - (y * 0.2);
	return ((r << 16) | (g << 8) | b);
}

int	shadow_dist(int color, double dist)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) / (dist * 0.5);
	g = ((color >> 8) & 0xFF) / (dist * 0.5);
	b = (color & 0xFF) / (dist * 0.5);
	return ((r << 16) | (g << 8) | b);
}
