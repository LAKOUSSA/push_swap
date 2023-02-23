/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:35:09 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/22 23:35:32 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list **b, t_list **a)
{
	t_list	*p;

	if (!(*b))
		return ;
	p = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = p;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*p;

	if (!(*a))
		return ;
	p = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = p;
}
