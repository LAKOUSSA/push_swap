/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 07:14:57 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 03:19:20 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_max(t_list *stack)
{
	t_index	index;
	t_index	i_max;
	int		max;

	index.i = 0;
	i_max.i = 0;
	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
		{
			max = stack->data;
			i_max.i = index.i;
		}
		stack = stack->next;
		index.i++;
	}
	return (i_max.i);
}

int	the_min(t_list *stack)
{
	t_index	index;
	t_index	i_min;
	int		min;

	i_min.i = 0;
	index.i = 0;
	min = stack->data;
	while (stack)
	{
		if (min > stack->data)
		{
			min = stack->data;
			i_min.i = index.i;
		}
		stack = stack->next;
		index.i++;
	}
	return (i_min.i);
}

void	sort_three(t_list **a)
{
	int	min;
	int	max;

	min = the_min(*a);
	max = the_max(*a);
	if (min == 1 && max == 2)
		swap(*a, "sa");
	else if (min == 2 && max == 0)
	{
		swap(*a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (min == 1 && max == 0)
		rotate(a, "ra");
	else if (min == 0 && max == 1)
	{
		swap(*a, "sa");
		rotate(a, "ra");
	}
	else
		reverse_rotate(a, "rra");
}

void	sort_five(t_list **a, t_list **b)
{
	int	i_min;
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		i_min = the_min(*a);
		if (i_min <= size / 2)
			while (i_min-- > 0)
				rotate(a, "ra");
		else
			while (i_min++ < size)
				reverse_rotate(a, "rra");
		push(a, b, "pb");
		size--;
	}
	if (size <= 3)
		sort_three(a);
	while ((*b) != NULL)
		push(b, a, "pa");
}

void	free_all(char **glob)
{
	int	i;

	i = 0;
	while (glob[i])
	{
		free(glob[i]);
		i++;
	}
	free(glob);
}
