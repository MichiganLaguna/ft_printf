/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:54:10 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/23 12:46:06 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_t;
	unsigned char	*s2_t;

	i = 0;
	s1_t = (unsigned char *)s1;
	s2_t = (unsigned char *)s2;
	while (i < n && s1_t[i] == s2_t[i])
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		return (s1_t[i - 1] - s2_t[i - 1]);
	return (s1_t[i] - s2_t[i]);
}
