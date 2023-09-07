/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:21:47 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/09/07 05:34:15 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*blend;
	char		*buffer;
	int			rd;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	blend = (char *)ft_calloc((1), sizeof(char));
	if (!BUFFER_SIZE || fd < 0 || !buffer || !blend)
	{
		free(buffer);
		buffer = NULL;	
		free(blend);
		blend = NULL;
		return (NULL);
	}
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
		buffer[rd] = '\0';
		blend = ft_strjoin(blend, buffer);
	}
	if (ft_strchr(blend, '\n'))
	{
		free(buffer);
		buffer = blend;
		remains = ft_strdup(ft_strchr(blend, '\n') + 1);
		blend = ft_calloc(ft_strlen(buffer) - ft_strlen(remains) + 1, sizeof(char));
		ft_strlcpy(blend, buffer, ft_strlen(buffer) - ft_strlen(remains) + 1);
	    if (buffer == blend)
        	buffer = NULL;
		else
		{
			free(buffer);
			buffer = NULL;
    	}
		return (blend);
	}
	else if (ft_strlen(blend) && rd >= 0 && rd < BUFFER_SIZE)
	{
		free(buffer);
		buffer = NULL;
		return (blend);
	}
	else
	{
		free(buffer);
		buffer = NULL;	
		free(blend);
		blend = NULL;
		return (NULL);
	}
}