/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:25 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 15:58:07 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // For debug prints

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!set)
	{
		str1 = ft_strdup(s1);
		return (str1);
	}
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= i && ft_strchr(set, s1[j]))
		j--;
	j = j - i + 1;
	if (j <= 0)
	{
		str1 = ft_strdup("");
		return (str1);
	}
	str1 = ft_substr(s1, i, j);
	return (str1);
}
