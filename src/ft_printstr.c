/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <nriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:17:33 by nriviere          #+#    #+#             */
/*   Updated: 2022/12/02 19:48:46 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_printstr(char *s)
{
	if (*s)
		return (ft_printchr(*s) + ft_printstr(s + 1));
	return (0);
}
