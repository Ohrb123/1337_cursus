/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:30:01 by oelharbi          #+#    #+#             */
/*   Updated: 2024/01/11 13:22:56 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (free(str), NULL);
	i = read(fd, s, BUFFER_SIZE);
	while (i > 0)
	{
		s[i] = '\0';
		str = ft_strjoin(str, s);
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
	static char	*line[OPEN_MAX];
	char		*str;

	str = NULL;
	if (BUFFER_SIZE <= 0 || read (fd, 0, 0) == -1)
		return (free(line[fd]), line[fd] = NULL, NULL);
	line[fd] = get_the_line(line[fd], fd);
	if (!line[fd] || *line[fd] == '\0')
		return (free(line[fd]), NULL);
	if (ft_strchr(line[fd], '\n'))
	{
		str = print_the_line(line[fd]);
		line[fd] = rest_line(line[fd]);
		if (!line[fd])
			return (free(str), NULL);
		return (str);
	}
	else if (!ft_strchr(line[fd], '\n'))
		return (str = ft_strjoin(str, line[fd]), \
		free(line[fd]), line[fd] = NULL, str);
	return (free(line[fd]), line[fd] = NULL, NULL);
}
