/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:40:13 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/10 17:57:12 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_putnbr_base(long nbr, char *base, int bsize)
{
	int				i;
	int				len;
	char			tmp[32];

	i = 0;
	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		len++;
	}
	if (nbr == 0)
		(write(1, base, 1), len++);
	while (nbr != 0)
	{
		tmp[i++] = base[nbr % bsize];
		nbr /= bsize;
		len++;
	}
	while (i--)
		write(1, &tmp[i], 1);
	return (len);
}

int	ft_charset(char format, char *charset)
{	
	int	i;

	i = 0;
	while (charset[i])
		if (charset[i] == format)
			return (1);
	return (0);
}

int	ft_printf(const char*format, ...)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	while (format[i[0]])
	{
		if (format[i[0]] == '%')
		{
			if (format[i[0] + 1] == 'x')
		}
		else
			write(1, &format[i[0]++], 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		write(1, "0x", 2);
		ft_putnbr_base((int)24748364859, DECBASE, 10);
	}
	return (0);
}
