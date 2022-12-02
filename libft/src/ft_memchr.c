/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:49:26 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/02 19:44:19 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_t;
	size_t			i;

	s_t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_t[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

