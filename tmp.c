#include <stddef.h>
#include <stdlib.h>

static int	ft_strchr(char *s, int c);
size_t	ft_strlen( char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_buffer(int fd, char *buffer);
char	*get_next_line(int fd);
char	*get_line(char *buffer);
char	*get_new_buffer_ptr(char *buffer);

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

int	main(void)
{
	static char	*fin;
	int		fd;

	fd = open("lorem.txt", O_RDONLY);
	fin = get_next_line(fd);
	printf("Output: %s\n", fin);
	printf("--------------------\n");
	free(fin);
	fin = get_next_line(fd);
	printf("Output: %s\n", fin);
	printf("--------------------\n");
	free(fin);
	fin = get_next_line(fd);
	printf("Output: %s\n", fin);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*gnl_buffer;
	char		*line;

	gnl_buffer = fill_buffer(fd, gnl_buffer);
	line = get_line(gnl_buffer);
	gnl_buffer = get_new_buffer_ptr(gnl_buffer);
	return (line);
}

char	*get_new_buffer_ptr(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	if(!buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	j = 0;
	while (buffer[j])
		j++;
	tmp = malloc(j - (i++) + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	free(buffer);
	return (tmp);
}

char	*fill_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		*(tmp + bytes_read) = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*tmp;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		tmp = malloc(i + 2);
	else
		tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

static int	ft_strchr(char *s, int c)
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
