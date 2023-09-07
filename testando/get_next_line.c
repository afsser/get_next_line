/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:21:47 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/09/07 19:29:07 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *blend)
{
	int		rd;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	rd = BUFFER_SIZE;
	while (!ft_strchr(blend, '\n') && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buffer[rd] = '\0';
		blend = ft_strjoin(blend, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (blend);
}

char	*treat_line(int rd, char *remains, char *blend)
{
	char	*temp;

	if (ft_strchr(blend, '\n'))
	{
		temp = blend;
		blend = ft_calloc(ft_strlen(temp) - ft_strlen(remains) + 1, 1);
		ft_strlcpy(blend, temp, ft_strlen(temp) - ft_strlen(remains) + 1);
		free(temp);
		temp = NULL;
		return (blend);
	}
	else if (ft_strlen(blend) && rd >= 0)
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
	static char	*remains;
	char		*blend;
	int			rd;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	// blend = (char *)ft_calloc((1), sizeof(char));
	blend = "";
	if (!blend)
	{
		free(blend);
		return (NULL);
	}
	if (remains)
	{
		blend = ft_strjoin(blend, remains);
		free(remains);
		remains = NULL;
	}
	rd = BUFFER_SIZE;
	blend = read_line(fd, blend);
	if (ft_strchr(blend, '\n'))
		remains = ft_strdup(ft_strchr(blend, '\n') + 1);
	return (treat_line(rd, remains, blend));
}
