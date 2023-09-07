/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:08:50 by nasser            #+#    #+#             */
/*   Updated: 2023/09/06 18:10:05 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// #include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (size < dst_len)
		return (src_len + size);
	else
		return (src_len + dst_len);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concatd_str;
	size_t	size_str;

	size_str = ft_strlen(s1) + ft_strlen(s2) + 1;
	concatd_str = (char *)malloc(size_str);
	if (!concatd_str)
		return (NULL);
	ft_strlcpy(concatd_str, s1, size_str);
	ft_strlcat(concatd_str, s2, size_str);
	free((void *)s1);
	return (concatd_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*dest;
	size_t			i;
	unsigned char	*p;

	dest = (void *)(malloc(nmemb * size));
	if (!dest || (!nmemb && !size && ((nmemb * size) / size) != nmemb))
		return (NULL);
	p = (unsigned char *)dest;
	i = 0;
	while (i < nmemb * size)
	{
		*p = '\0';
		p++;
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*buffer;
	char		*blend;
	int			rd;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	blend = ft_strdup("");
	if (remains)
    {
		blend = ft_strjoin(blend, remains);
        free(remains);
        remains = NULL;
    }
    rd = BUFFER_SIZE;
	while (!ft_strchr(blend, '\n') && rd == BUFFER_SIZE)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		blend = ft_strjoin(blend, buffer);
	}
    if (rd)
	{
		buffer = blend;
		remains = ft_strdup(ft_strchr(blend, '\n') + 1);
		blend = ft_calloc(ft_strlen(buffer) - ft_strlen(remains) + 1, sizeof(char));
		// blend[ft_strlen(buffer) - ft_strlen(remains)] = '\0';
		ft_strlcpy(blend, buffer, ft_strlen(buffer) - ft_strlen(remains) + 1);
		free(buffer);
		buffer = NULL;
		return ((unsigned char *)blend);
	}
	free(remains);
	remains = NULL;
	free(buffer);
	buffer = NULL;	
	free(blend);
	blend = NULL;
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*s;

	fd = open("file.txt", O_RDONLY);
	i = 0;
	while (i < 100)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	// fd = open("gpt.txt", O_RDONLY);
	// i = 0;
	// while (i < 23)
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// 	i++;
	// }
}