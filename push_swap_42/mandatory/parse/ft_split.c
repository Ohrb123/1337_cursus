/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:12:29 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:12 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_fill_word(const char *s, int start, int end)
{
	char	*str;

	str = malloc((end - start) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, (end - start) + 1);
	str[end - start] = '\0';
	return (str);
}

static int	ft_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	*ft_free(char **s, int count)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free (s);
	return (NULL);
}

static char	**strings_allocate(const char *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int			check;
	int			j;
	int			i;
	char		**words;

	words = strings_allocate(s, c);
	if (words == NULL)
		return (NULL);
	i = -1;
	check = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && check < 0)
			check = i;
		else if ((s[i] == c || i == ft_strlen(s)) && check >= 0)
		{
			words[j] = ft_fill_word(s, check, i);
			if (words[j++] == NULL)
				return (ft_free(words, j));
			check = -1;
		}
	}
	words[j] = NULL;
	return (words);
}
