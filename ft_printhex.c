/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:19:16 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/29 17:56:53 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_power(int n, int power)
{
	int	pow;

	if (power == 0)
		return (1);
	pow = ft_power(n, power / 2);
	if (power & 1)
		return (n * pow * pow);
	return (pow * pow);
}

static int	ft_get_size(int c)
{
	if (c / 16 == 0)
		return (1);
	return (1 + ft_get_size(c / 16));
}

static char	*ft_get_str_hex(int c)
{
	char			*out;
	int				size;
	int				i;
	unsigned int	n_tmp;

	size = ft_get_size(c);
	i = 0;
	if (c < 0)
		i++;
	out = malloc((size + i + 1) * sizeof(char));
	if (!out)
		return (out);
	n_tmp = (unsigned int)c;
	if (i)
	{
		out[0] = '-';
		n_tmp = (unsigned int)-c;
	}
	while (size--)
	{
		out[i] = HEXABASE[(n_tmp / ft_power(16, size) % 16)];
		i++;
	}
	return (out);
}

int	ft_printhex(int c, int max)
{
	char	*out;
	int		i;

	out = ft_get_str_hex(c);
	if (!out)
		return (0);
	if (max)
	{
		i = 0;
		while (out[i])
		{
			out[i] = ft_toupper(out[i]);
			i++;
		}
	}
	ft_putstr_fd(out, 1);
	return (ft_get_size(c));
}
