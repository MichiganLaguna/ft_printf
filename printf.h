/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:21:09 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/29 17:47:09 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define FLAG_START '%'
# define PERIOD '.'
# define ARGS_TYPE "cspdiuxX%"
# define FLAGS "-0# +"
# define HEXABASE "0123456789abcdef"

int	ft_printstr(char *str);
int	ft_printchr(char chr);
int	ft_printhex(int n, int max);
int	ft_printnbr(int nbr);
int	ft_printu_int(unsigned int u_int);

#endif // PRINTF_H