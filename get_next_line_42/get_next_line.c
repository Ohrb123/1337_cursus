/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:30:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/01/11 13:23:11 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*print_the_line(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	++i;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	while (line[j] != '\n' && j < i)
	{
		result[j] = line[j];
		j++;
	}
	result[j] = '\n';
	result[j + 1] = '\0';
	return (result);
}

char	*rest_line(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	++i;
	result = malloc((ft_strlen(line) + i) + 1);
	if (!result)
		return (NULL);
	while (line[i] && i < ft_strlen(line))
	{
		result[j] = line[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(line);
	return (result);
}

char	*get_the_line(char	*str, int fd)
{
	char	*s;
	int		i;

	s = malloc((size_t)BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	i = read(fd, s, BUFFER_SIZE);
	while (i > 0)
	{
		s[i] = '\0';
		str = ft_strjoin(str, s);
		if (!str)
			return (free(s), NULL);
		if (ft_strchr(s, '\n'))
			break ;
		i = read(fd, s, BUFFER_SIZE);
	}
	free(s);
	if (i < 0)
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_the_line(line, fd);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	if (ft_strchr(line, '\n'))
	{
		str = print_the_line(line);
		line = rest_line(line);
		if (!line)
			return (free(str), NULL);
		return (str);
	}
	else
	{
		str = ft_strjoin(str, line);
		return (free(line), line = NULL, str);
	}
	return (free(line), line = NULL, NULL);
}
