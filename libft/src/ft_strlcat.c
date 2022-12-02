/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:58:01 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/23 13:03:25 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if ((size == 0) & (!dst || !src))
		return (0);
	while (dst[l] && l < size)
		l++;
	while (i + l < size - 1 && src[i] && size)
	{
		dst[l + i] = src[i];
		i++;
	}
	if (l < size)
		dst[l + i] = '\0';
	return (l + ft_strlen(src));
}
