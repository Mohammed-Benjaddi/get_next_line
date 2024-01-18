/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <ben-jad@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:34:32 by mben-jad          #+#    #+#             */
/*   Updated: 2024/01/18 19:26:02 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	if(!res)
		return NULL;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	dst_size;
	int	srcsize;
	int	i;

	dst_size = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while (src[i] && dst_size + i < dstsize - 1)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = '\0';
	}
	if (dstsize <= dst_size)
		return (srcsize + dstsize);
	return (dst_size + srcsize);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	src_size;
	int	i;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
