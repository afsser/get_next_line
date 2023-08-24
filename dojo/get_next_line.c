/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:38:32 by mdias             #+#    #+#             */
/*   Updated: 2023/08/24 19:50:28 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			rd;
	char		*blend;
	static char	*remains;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	// rd = 1;
	// rd = read(fd, buffer, BUFFER_SIZE);
	blend = malloc(0);
	if (remains)
		blend = ft_strjoin(blend, remains);
	while (!ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (!rd)
			return (0);
		blend = ft_strjoin(blend, buffer);
		if (rd < BUFFER_SIZE)
			return (buffer);
	}
	if (ft_strchr(blend, '\n'))
	{
		buffer = blend;
		remains = ft_strdup(ft_strchr(blend, '\n') + 1);
		blend[ft_strlen(blend) - ft_strlen(ft_strchr(blend, '\n')) + 1] = '\0';
		blend = ft_strdup(blend);
		free(buffer);
		buffer = NULL;
		return (blend);
	}
	else if (!*buffer)
	{
		free(remains);
		remains = NULL;
		return (blend);
	}
	else if (rd == 1 || rd == 0)
		return (0);
	return (0);
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
	while (i < 66)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
		free(s);
	}
	// close(fd);
}
/*
cccccccccccccccccccc
.
xxxxxxxxxxxxxxxx
rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
00000000000000000000000000000
222222222222222
999999999999999
*/