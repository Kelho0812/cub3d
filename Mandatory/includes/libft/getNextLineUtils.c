/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getNextLineUtils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:46:54 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 09:47:03 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getNextLine/getNextLine.h"

char	*ft_strjoin_get(char *s1, const char *s2)
{
	char	*new_str;
	int		i;
	int		n;

	if (!s1)
		s1 = ft_calloc_get(1, 1);
	if (!s2)
		return (NULL);
	new_str = ft_calloc_get(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		new_str[n++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[n++] = s2[i++];
	}
	new_str[n] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr_get(char *s)
{
	int		i;
	char	*s1;

	i = 0;
	if (!*s)
	{
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	s1 = ft_calloc_get(i + 2, 1);
	if (!s1)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_calloc_get(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (nmemb--)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
