/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:45:14 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/20 11:41:47 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	is_charset(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	end;
	int	start;

	if (s1 == 0)
		return (ft_strdup(""));
	if (set == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != 0 && is_charset(s1[start], set) == 1)
		start++;
	if (start == end + 1)
		return (ft_strdup(""));
	while (is_charset(s1[end], set) == 1)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
