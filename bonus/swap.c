/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:34:18 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 00:04:42 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *a)
{
	int	x;

	if (!a || a->next == NULL)
		return ;
	x = a->data;
	a->data = a->next->data;
	a->next->data = x;
}

void	sb(t_list *b)
{
	int	x;

	if (!b || b->next == NULL)
		return ;
	x = b->data;
	b->data = b->next->data;
	b->next->data = x;
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}
