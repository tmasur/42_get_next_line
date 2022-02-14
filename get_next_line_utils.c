/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:03:34 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/14 17:04:54 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strlen( char *s)
{
	char	*ptr_s;

	if (!s)
		return (0);
	ptr_s = s;
	while (*ptr_s)
		ptr_s++;
	return (ptr_s - s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	char	*r_tmp;
	char	*s1_tmp;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	r_tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_tmp)
		return (NULL);
	r = r_tmp;
	s1_tmp = s1;
	while (*s1_tmp)
		*(r_tmp++) = *s1_tmp++;
	while (*s2)
		*(r_tmp++) = *s2++;
	*(r_tmp) = '\0';
	free(s1);
	return (r);
}
