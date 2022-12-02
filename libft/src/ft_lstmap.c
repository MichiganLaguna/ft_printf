/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:12:44 by nriviere          #+#    #+#             */
/*   Updated: 2022/11/23 15:46:38 by nriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;
	t_list	*out;

	if (!lst || !f || !del)
		return (0);
	tmp = lst->next;
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (start);
	lst = tmp;
	while (lst)
	{
		tmp = lst->next;
		out = ft_lstnew(f(lst->content));
		if (!out)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, out);
		lst = tmp;
	}
	return (start);
}
