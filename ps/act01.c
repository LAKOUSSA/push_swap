/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:50:10 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 05:19:37 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **h, char *s)
{
	t_list	*last;
	t_list	*p;

	if (*h == NULL || (*h)->next == NULL)
		return ;
	last = *h;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	p->next = NULL;
	last->next = *h;
	*h = last;
	if (s)
		ft_putendl_fd(s, 1);
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_putendl_fd("rrr", 1);
}

void	printerror(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int	is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_not_empty(t_list *a, t_array array, t_info info)
{
	while (a)
	{
		if (a->data >= array.t[info.start] && a->data <= array.t[info.end])
			return (1);
		a = a->next;
	}
	return (0);
}
