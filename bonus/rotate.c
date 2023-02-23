/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:37:46 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 01:09:14 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **a)
{
	t_list	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
}

void	rb(t_list **b)
{
	t_list	*temp;

	if (!(*b) || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
