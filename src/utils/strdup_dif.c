/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_dif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:05:23 by ruiolive          #+#    #+#             */
/*   Updated: 2024/08/01 12:05:23 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup_dif(const char *s, int size)
{
	char	*s_copy;
	int		i;

	s_copy = ft_calloc(size + 1, 1);
	i = 0;
	if (!s_copy)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
