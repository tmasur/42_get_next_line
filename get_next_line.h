/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:06:00 by tmasur            #+#    #+#             */
/*   Updated: 2022/02/14 17:06:26 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *s, int c);
size_t	ft_strlen( char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_buffer(int fd, char *buffer);
char	*get_next_line(int fd);
char	*get_line(char *buffer);
char	*get_new_buffer_ptr(char *buffer);
#endif
