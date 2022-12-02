/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:11:09 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/20 12:29:01 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = (unsigned int)ft_strlen(s);
	if (len_s < start)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	i = 0;
	out = ft_calloc(len + 1, sizeof(char));
	if (out)
	{
		while (i < len && s[start + i])
		{
			out[i] = s[start + i];
			i++;
		}
	}
	return (out);
}
