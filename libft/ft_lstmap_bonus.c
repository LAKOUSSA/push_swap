/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:22:13 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/20 09:37:35 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nl;

	nl = 0;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->data));
		if (!new)
		{
			ft_lstclear(&nl, del);
			return (nl);
		}
		ft_lstadd_back(&nl, new);
		lst = lst->next;
	}
	return (nl);
}
