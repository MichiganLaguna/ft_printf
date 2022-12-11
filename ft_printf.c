/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:05:48 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/11 05:53:30 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static int	_ft_putnbrb(long nbr, char *base, int bsize)
{
	int		i;
	int		len;
	char	tmp[30];

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
		(write(1, &tmp[i], 1), len++);
	return (len);
}

static int	_strnchr(char format, va_list *args)
{
	char	*tmp;
	char	tmp_c;
	int		i;

	if (format == 'c')
	{
		tmp_c = va_arg(*args, int);
		write(1, &tmp_c, 1);
		return (1);
	}
	else
	{
		i = 0;
		tmp = va_arg(*args, char *);
		if (!tmp)
			return (write(1, "(null)", 6), 6);
		while (tmp[i])
			write(1, &(tmp[i++]), 1);
		return (i);
	}
}

static int	_flagfinder(char format, va_list *args)
{
	if (format == 'c')
		return (_strnchr(format, args));
	else if (format == 's')
		return (_strnchr(format, args));
	else if (format == 'p')
		return (write(1, "0x", 2),
			_ft_putnbrb(va_arg(*args, signed long), "0123456789abcdef", 16) + 2);
	else if (format == 'd' || format == 'i')
		return (_ft_putnbrb(va_arg(*args, int), "0123456789", 10));
	else if (format == 'u')
		return (_ft_putnbrb(va_arg(*args, unsigned int), "0123456789", 10));
	else if (format == 'x')
		return (_ft_putnbrb(va_arg(*args, long), "0123456789abcdef", 16));
	else if (format == 'X')
		return (_ft_putnbrb(va_arg(*args, long), "0123456789ABCDEF", 16));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i[3];
	va_list	args;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	va_start(args, format);
	while (format[i[0]])
	{
		if (format[i[0]] == '%' && format[i[0] + 1])
		{
			if (format[i[0] + 1] == '%')
				write(1, "%", 1);
			i[1] = _flagfinder(format[i[0] + 1], &args);
			if (i[1])
				i[0]++;
			i[2] += i[1];
		}
		else
			(write(1, &format[i[0]], 1), i[2]++);
		i[0]++;
	}
	va_end(args);
	return (i[2]);
}
