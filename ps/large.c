/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:50:08 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 01:52:14 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	creat_sort_array(t_list *a)
{
	t_array	array;

	array.index.i = -1;
	array.size = ft_lstsize(a);
	array.t = malloc(sizeof(int) * array.size);
	while (a)
	{
		array.t[++array.index.i] = a->data;
		a = a->next;
	}
	array.index.i = -1;
	while (++array.index.i < array.size - 1)
	{
		array.index.j = array.index.i;
		while (++array.index.j < array.size)
		{
			if (array.t[array.index.i] > array.t[array.index.j])
			{
				array.swap = array.t[array.index.i];
				array.t[array.index.i] = array.t[array.index.j];
				array.t[array.index.j] = array.swap;
			}
		}
	}
	return (array);
}

void	first_push(t_list **a, t_list **b, t_array array, t_info info)
{
	while (*a)
	{
		while (is_not_empty(*a, array, info))
		{
			if ((*a)->data >= array.t[info.start]
				&& (*a)->data <= array.t[info.end])
			{
				push(a, b, "pb");
				if ((*b)->data < array.t[info.mid])
					rotate(b, "rb");
			}
			else
				rotate(a, "ra");
		}
		info.start -= info.offset;
		info.end += info.offset;
		if (info.start < 0)
			info.start = 0;
		if (info.end >= array.size)
			info.end = array.size - 1;
	}
}

int	search_next(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

void	push_back(t_list **a, t_list **b, int size)
{
	while (*b || !is_sorted(*a))
	{
		if (*b && (*b)->index == (*a)->index - 1)
			push(b, a, "pa");
		else if (ft_lstlast(*a)->index == (*a)->index - 1)
			reverse_rotate(a, "rra");
		else if (*b && (ft_lstlast(*a)->index == size - 1
				|| (*b)->index > ft_lstlast(*a)->index))
		{
			push(b, a, "pa");
			rotate(a, "ra");
		}
		else if (ft_lstsize(*b) > 1)
		{
			if (search_next(*b, (*a)->index - 1) < ft_lstsize(*b) / 2)
				rotate(b, "rb");
			else
				reverse_rotate(b, "rrb");
		}
	}
}

void	large_sort(t_list **a, t_list **b)
{
	t_array	array;
	t_info	info;
	t_list	*temp;
	int		max;

	array = creat_sort_array(*a);
	index_stack(a, array);
	info = get_info(array);
	temp = *a;
	first_push(a, b, array, info);
	max = max_of_b(*b);
	info.place = get_place(*b, max, info);
	while (info.place-- > 0)
		rotate(b, "rb");
	push(b, a, "pa");
	push_back(a, b, array.size);
	free(array.t);
}
