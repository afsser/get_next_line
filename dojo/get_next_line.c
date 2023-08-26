/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipenasser <felipenasser@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:21:32 by felipenasse       #+#    #+#             */
/*   Updated: 2023/08/25 20:59:51 by felipenasse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*buffer;
	char		*blend;
	int			rd;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	blend = (char *)ft_calloc(1, 1);
	if (remains)
    {
		blend = ft_strjoin(blend, remains);
        free(remains);
        remains = NULL;
    }
    rd = BUFFER_SIZE;
	while (!ft_strchr(buffer, '\n') && rd == BUFFER_SIZE)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
        if (rd > 0)
		{
		    blend = ft_strjoin(blend, buffer);
		}
	}
	if (*buffer && rd)
	{
        if (rd == BUFFER_SIZE)
        {
		    buffer = blend;
		    remains = ft_strdup(ft_strchr(blend, '\n') + 1);
		    blend = ft_calloc(ft_strlen(buffer) - ft_strlen(remains) + 1, sizeof(char));
		    ft_strlcpy(blend, buffer, ft_strlen(buffer) - ft_strlen(remains) + 1);
        }
		else if (rd < BUFFER_SIZE)
		{
			return (NULL);
		}
		free(buffer);
		buffer = NULL;
		return (blend);
	}
	free(buffer);
	free(blend);
	buffer = NULL;
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
	while (i < 200)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
}