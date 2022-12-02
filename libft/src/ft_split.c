/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:02:09 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/20 12:17:42 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_words(const char *s, char sep)
{
	int	length;
	int	words;

	length = 0;
	words = 0;
	while (*s)
	{
		if (*s == sep)
		{
			if (length > 0)
			{
				words++;
				length = 0;
			}
		}
		else
			length++;
		s++;
	}
	if (length)
		words++;
	return (words);
}

static int	ft_get_next_word(const char *s, char c, char **out)
{
	int	start;
	int	length;

	start = 0;
	length = 0;
	while (s[start] && s[start] == c)
		start++;
	while (s[start + length] && s[start + length] != c)
		length++;
	*out = ft_substr(s, start, length);
	return (start + length);
}

void	ft_split_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		size;
	int		i;
	int		ln;

	if (!s)
		return (0);
	size = ft_get_words(s, c);
	out = ft_calloc(size + 1, sizeof(char *));
	ln = 0;
	i = 0;
	if (!out)
		return (out);
	while (i < size)
	{
		ln += ft_get_next_word(s + ln, c, &out[i]);
		if (!out[i])
		{
			ft_split_free(out);
			return (out);
		}
		i++;
	}
	out[i] = 0;
	return (out);
}
