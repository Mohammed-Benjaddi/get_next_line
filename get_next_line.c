/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <ben-jad@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:55:00 by mben-jad          #+#    #+#             */
/*   Updated: 2024/01/18 23:11:31 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;
	// char *temp = s2;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);\
	if (!s1)
		return ft_strdup(s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcpy(res + s1_len, s2, s1_len + s2_len + 1);
	free(s1);
	// printf("strjoin: %s\n", res);
	return (res);
}

char	*found_new_line(char **res, int index)
{
	char	*line;
	char	*temp_res;
	int		i;

	i = 0;
	line = malloc(index + 1);
	if (!line)
		return (NULL);
	temp_res = ft_strdup(*res + (index));
	if (!temp_res)
		return (NULL);
	while (i < index)
	{
		line[i] = *(*res + i);
		i++;
	}
	line[i] = '\0';
	free(*res);
	*res = ft_strdup(temp_res);
	if(!res)
		return NULL;
	free(temp_res);
	return (line);
}

char	*handle_res(char **res)
{
	char	*line;
	char	*temp;
	int		i;
	int		index;

	temp = NULL;
	i = 0;
	index = ft_strchr(*res, '\n');
	if (index != -1)
	{
		line = found_new_line(res, index);
		if(!line)
			return NULL;
	}
	else
	{
		line = ft_strdup(*res);
		if(!line)
			return NULL;
		free(*res);
		*res = NULL;
	}
	if (!ft_strlen(line))
	{
		free(line);
		line = NULL;
	}
	return (line);
}

// char free_res()

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buff;
	int			counter;
	char		*line;
	int			newline_in_buff;

	buff = NULL;
	newline_in_buff = -1;
	if (read(fd, "", 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	while (newline_in_buff == -1)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if(!buff)
			return NULL;
		counter = read(fd, buff, BUFFER_SIZE);
		buff[counter] = '\0';
		if (counter <= 0)
		{
			free(buff);
			buff = NULL;
			break ;
		}
		newline_in_buff = ft_strchr(buff, '\n');
		res = ft_strjoin(res, buff);
		if(!res)
			return NULL;
		free(buff);
		buff = NULL;
	}
	line = handle_res(&res);
	return (line);
}
