/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:38:57 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/21 22:54:36 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	get_info(t_array array)
{
	t_info	info;

	info.mid = array.size / 2 - 1;
	if (array.size <= 100)
		info.div = 5;
	else
		info.div = 11;
	info.offset = array.size / info.div;
	info.start = info.mid - info.offset;
	info.end = info.mid + info.offset;
	return (info);
}

int	get_place(t_list *a, int data, t_info info)
{
	info.place = 0;
	while (a)
	{
		if (a->data == data)
			return (info.place);
		info.place++;
		a = a->next;
	}
	return (info.place);
}

int	max_of_b(t_list *b)
{
	int	max;

	max = b->data;
	while (b)
	{
		if (b->data > max)
			max = b->data;
		b = b->next;
	}
	return (max);
}

int	get_index(t_array array, int data)
{
	int	index;

	index = 0;
	while (index < array.size)
	{
		if (array.t[index] == data)
			return (index);
		index++;
	}
	return (index);
}

void	index_stack(t_list **stack, t_array array)
{
	t_list	*head;

	head = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = get_index(array, (*stack)->data);
		(*stack) = (*stack)->next;
	}
	*stack = head;
}
