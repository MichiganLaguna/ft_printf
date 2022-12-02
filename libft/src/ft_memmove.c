/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:21 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/20 12:42:50 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_t;
	unsigned const char	*src_t;
	size_t				i;
	int					right;

	if (!dest && !src)
		return (dest);
	i = 0;
	right = 1;
	src_t = src;
	dest_t = dest;
	if (src_t - dest_t < 0)
		right = -1;
	i = 1;
	if (right < 0)
		i = n;
	while (i <= n && i > 0)
	{
		dest_t[i - 1] = src_t[i - 1];
		i += right;
	}
	return (dest);
}
