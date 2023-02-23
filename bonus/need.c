/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:50:10 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 04:10:59 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printerror(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

int	is_sorted(t_list *a, t_list *b)
{
	if (!a || b)
		return (0);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
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

int	equal_and_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	which_instruction(t_list **a, t_list **b, char *act)
{
	if (equal_and_same(act, "sa\n"))
		sa(*a);
	else if (equal_and_same(act, "sb\n"))
		sb(*b);
	else if (equal_and_same(act, "ss\n"))
		ss(*a, *b);
	else if (equal_and_same(act, "pa\n"))
		pa(b, a);
	else if (equal_and_same(act, "pb\n"))
		pb(a, b);
	else if (equal_and_same(act, "ra\n"))
		ra(a);
	else if (equal_and_same(act, "rb\n"))
		rb(b);
	else if (equal_and_same(act, "rr\n"))
		rr(a, b);
	else if (equal_and_same(act, "rra\n"))
		rra(a);
	else if (equal_and_same(act, "rrb\n"))
		rrb(b);
	else if (equal_and_same(act, "rrr\n"))
		rrr(a, b);
	else
		printerror("ERROR");
}
