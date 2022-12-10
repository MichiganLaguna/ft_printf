/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:05:48 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/10 18:21:50 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static int	_ft_putnbr_base(long nbr, char *base, int bsize)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	if (nbr < 0)
		(write(1, "-", 1), len++);
	if (nbr == 0)
		(write(1, base, 1), len++);
	while (nbr != 0)
	{
		tmp[i] = base[nbr % bsize];
		nbr /= bsize;
		i++;
	}
	while (i--)
		write(1, &tmp[i], 1);
	return (len);
}

static int	_flagfinder(char format, va_list args)
{
	char	*tmp;

	if (format == 'c')
		return (write(1, va_arg(args, char), 1), 1);
	else if (format == 's')
	{
		tmp = va_arg(args, char *);
		while (*tmp)
			write (1, tmp++, 1);
	}
	else if (format == 'p')
		(write(1, "0x", 2), _ft_putnbr_base((signed long)va_arg(args, void *), HEXBASE, 16));
	else if (format == 'd' || format == 'i')
		_ft_putnbr_base(va_arg(args, int))
	else if (format == 'u')
	else if (format == 'x')
	else if (format == 'X')
	return (0);

}