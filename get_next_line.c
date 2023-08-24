/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:21:47 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/08/23 19:49:55 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	count_line(char *buffer)
{
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE + 1];

	read(fd, BUFFER_SIZE, MAX_FD);
}
/* RETURN :
Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred */
int	main(void)
{
	
}