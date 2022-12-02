/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:38 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/02 19:48:51 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_printu_int(unsigned int u_int)
{
	int	sum;

	if (u_int / 10 == 0)
	{
		ft_putchar_fd(u_int + 48, 1);
		return (1);
	}
	else
	{
		sum = ft_printu_int(u_int / 10);
		ft_putchar_fd(u_int % 10 + 48, 1);
		return (1 + sum);
	}
}
