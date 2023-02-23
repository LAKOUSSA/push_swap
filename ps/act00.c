/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:24:54 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/22 23:41:12 by gloukas          ###   ########.fr       */
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
		ft_printf("%s\n", s);
}

void	swap_both(t_list *a, t_list *b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_printf("ss\n");
}

void	push(t_list **from, t_list **to, char *s)
{
	t_list	*p;

	if (!(*from))
		return ;
	p = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = p;
	ft_printf("%s\n", s);
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
		ft_printf("%s\n", s);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_printf("rr\n");
}
