/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:53:08 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/23 11:28:15 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ptr;

	if (!n)
		return (malloc(0));
	if (nmemb * n / n != nmemb)
		return (0);
	ptr = malloc(nmemb * n);
	if (ptr)
		ft_bzero(ptr, nmemb * n);
	return (ptr);
}
