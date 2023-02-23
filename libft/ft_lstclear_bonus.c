/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:21:21 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/20 09:37:25 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!*lst || !lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		p = p->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
}
