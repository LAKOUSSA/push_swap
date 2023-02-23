/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beggin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:14:29 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 04:11:55 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(char **glob)
{
	t_index	index;

	index.i = -1;
	while (glob[++index.i])
	{
		index.j = -1;
		while (glob[index.i][++index.j])
			if (glob[index.i][index.j] != '-' && glob[index.i][index.j] != '+'
				&& glob[index.i][index.j] != '\t'
				&& glob[index.i][index.j] != ' '
				&& (glob[index.i][index.j] < '0'
					|| glob[index.i][index.j] > '9'))
				printerror("ERROR");
	}
	index.i = -1;
	while (glob[++index.i])
	{
		index.j = index.i + 1;
		while (glob[index.j])
		{
			if (ft_atoi(glob[index.i]) == ft_atoi(glob[index.j]))
				printerror("ERROR");
			index.j++;
		}
	}
}

char	**join_args(int ac, char *av[])
{
	t_index	index;
	char	*line;
	char	**glob;

	if (ac == 1)
		exit(0);
	line = NULL;
	glob = NULL;
	index.i = 0;
	while (++index.i < ac)
	{
		if (!ft_strlen(av[index.i]))
			printerror("ERROR");
		index.j = 0;
		while (av[index.i][index.j] == '\t' || av[index.i][index.j] == ' ')
			index.j++;
		if (index.j == ft_strlen(av[index.i]))
			printerror("ERROR");
		line = ft_strjoin(line, av[index.i]);
	}
	glob = ft_split(line, ' ');
	free(line);
	check_args(glob);
	return (glob);
}

t_list	*to_stack(char **glob)
{
	t_index		index;
	long int	n;
	t_list		*a;

	index.i = -1;
	while (glob[++index.i])
	{
		n = ft_atoi(glob[index.i]);
		if (n > INT_MAX || n < INT_MIN)
			printerror("ERROR");
		if (index.i == 0)
			a = ft_lstnew(n);
		else
			ft_lstadd_back(&a, ft_lstnew(n));
	}
	free_all(glob);
	return (a);
}

void	which_function(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (!is_sorted(*a))
	{
		if (len > 1 && len <= 3)
			sort_three(a);
		else if (len <= 5)
			sort_five(a, b);
		else
			large_sort(a, b);
	}
}

int	main(int ac, char *av[])
{
	char	**glob;
	t_list	*a;
	t_list	*b;

	glob = join_args(ac, av);
	a = to_stack(glob);
	which_function(&a, &b);
}
