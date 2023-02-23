/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:47:36 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/22 00:45:48 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*p;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	p->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*p;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	p->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
