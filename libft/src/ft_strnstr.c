/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:23:28 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/23 15:52:44 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != 0)
	{
		if (big[i] == *little)
			if (len_little + i <= len)
				if (ft_strncmp(big + i, little, len_little) == 0)
					return ((char *)big + i);
		i++;
	}
	return (0);
}
