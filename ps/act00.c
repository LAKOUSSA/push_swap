/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:24:54 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 06:31:58 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *h, char *s)
{
	int	x;

	if (!h)
		return ;
	x = h->data;
	h->data = h->next->data;
	h->next->data = x;
	if (s)
		ft_putendl_fd(s, 1);
}

void	swap_both(t_list *a, t_list *b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_putendl_fd("ss", 1);
}

void	push(t_list **from, t_list **to, char *s)
{
	t_list	*p;

	if (!(*from))
		return ;
	p = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = p;
	ft_putendl_fd(s, 1);
}

void	rotate(t_list **h, char *s)
{
	t_list	*temp;

	if (!(*h))
		return ;
	temp = *h;
	*h = (*h)->next;
	temp->next = NULL;
	ft_lstadd_back(h, temp);
	if (s)
		ft_putendl_fd(s, 1);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_putendl_fd("rr", 1);
}
