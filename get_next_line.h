/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <ben-jad@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:26:46 by mben-jad          #+#    #+#             */
/*   Updated: 2024/01/18 14:22:15 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

 #ifndef BUFFER_SIZE
  #define BUFFER_SIZE 10
 #endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strchr(char *s, char c);
char *ft_strdup(char *str);
int	ft_strlcat(char *dst, char *src, int dstsize);
int	ft_strlcpy(char *dst, char *src, int dstsize);

#endif
