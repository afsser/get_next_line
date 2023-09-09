/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:21:47 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/09/09 17:00:34 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// static char	*ft_strjoin(const char *s1, const char *s2);
// static char	*clean_buffer(char *buffer);
// static char	*read_line(int fd, char *blend);
// static char	*treat_line(char *remains, char *blend);

static char	*clean_buffer(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
	{
		free((void *)s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((void *)s1);
	return (str);
}

static char	*read_line(int fd, char *blend)
{
	int		rd;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (clean_buffer(buffer));
	rd = BUFFER_SIZE;
	while (!ft_strchr(blend, '\n') && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			free(blend);
			blend = NULL;
			return (clean_buffer(buffer));
		}
		buffer[rd] = '\0';
		blend = ft_strjoin(blend, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (blend);
}

static char	*treat_line(char *remains, char *blend)
{
	char	*temp;

	if (ft_strchr(blend, '\n'))
	{
		temp = blend;
		blend = ft_calloc(ft_strlen(temp) - ft_strlen(remains) + 1, 1);
		if (!blend)
		{
			free(blend);
			blend = NULL;
			return (NULL);
		}
		ft_strlcpy(blend, temp, ft_strlen(temp) - ft_strlen(remains) + 1);
		free(temp);
		temp = NULL;
		return (blend);
	}
	else if (ft_strlen(blend))
		return (blend);
	else
	{
		free(blend);
		blend = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*remains[1024];
	char		*blend;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	blend = (char *)ft_calloc((1), sizeof(char));
	if (!blend)
	{
		free(blend);
		return (NULL);
	}
	if (remains[fd])
	{
		blend = ft_strjoin(blend, remains[fd]);
		free(remains[fd]);
		remains[fd] = NULL;
	}
	blend = read_line(fd, blend);
	if (!blend)
		return (NULL);
	if (ft_strchr(blend, '\n'))
		remains[fd] = ft_strdup(ft_strchr(blend, '\n') + 1);
	return (treat_line(remains[fd], blend));
}
