/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:50:10 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/21 22:54:31 by gloukas          ###   ########.fr       */
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
		ft_printf("%s\n", s);
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_printf("rrr\n");
}

void	printerror(char *s)
{
	ft_printf("%s\n", s);
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
