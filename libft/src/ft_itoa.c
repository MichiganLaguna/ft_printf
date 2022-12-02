/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:21:51 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/28 17:21:55 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_char_size(int n, int base)
{
	if (n / base == 0)
		return (1);
	return (1 + ft_get_char_size(n / base, base));
}

static	int	ft_power(int n, int power)
{
	int	pow;

	if (power == 0)
		return (1);
	pow = ft_power(n, power / 2);
	if (power & 1)
		return (n * pow * pow);
	return (pow * pow);
}

char	*ft_itoa(int n)
{
	char			*out;
	int				size;
	int				i;
	unsigned int	n_tmp;

	size = ft_get_char_size(n, 10);
	i = 0;
	if (n < 0)
		i++;
	out = ft_calloc(sizeof(char), size + i + 1);
	if (!out)
		return (out);
	n_tmp = (unsigned int)n;
	if (i)
	{
		out[0] = '-';
		n_tmp = (unsigned int )-n;
	}
	while (size--)
	{
		out[i] = (n_tmp / ft_power(10, size) % 10) + 48;
		i++;
	}
	return (out);
}
