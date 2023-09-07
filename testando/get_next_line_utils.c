/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:26:05 by fcaldas-          #+#    #+#             */
/*   Updated: 2023/09/07 19:03:35 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	concatd_str = (char *)ft_calloc(size_str, sizeof(char));
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
