/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getNextLine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe  <jorteixe@student.42porto.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:42:53 by jorteixe          #+#    #+#             */
/*   Updated: 2024/07/22 09:43:05 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_get(char *s1, const char *s2);
int		has_newline(char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr_get(char *s);
size_t	ft_newlinelen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_clean_str(char *str);
char	*ft_calloc_get(size_t nmemb, size_t size);
char	*norminettenz(char **str, char **buffer_str);

#endif