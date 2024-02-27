/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:17:17 by oelharbi          #+#    #+#             */
/*   Updated: 2024/01/11 11:46:44 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (s[start] && (int)start < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *buff)
{
	char	*str;
	int		i;
	int		x;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = ft_strlen(s1);
	x = ft_strlen(buff);
	if (!buff)
		return (free(s1), NULL);
	str = malloc(i + x + 1);
	if (!str)
		return (free(s1), NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, buff, x);
	str[i + x] = '\0';
	return (free(s1), s1 = NULL, str);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
