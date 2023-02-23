/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:34:54 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 04:16:12 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "unistd.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_index
{
	int	i;
	int	j;
}	t_index;

/*CHECKER*/
void	check_args(char **glob);
char	**join_args(int ac, char *av[]);
t_list	*to_stack(char **glob);
/*NEED*/
void	printerror(char *s);
int		is_sorted(t_list *a, t_list *b);
void	free_all(char **glob);
int		equal_and_same(char *s1, char *s2);
void	which_instruction(t_list **a, t_list **b, char *act);
/*SWAP*/
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
/*PUSH*/
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);
/*ROTATE*/
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
/*REVERSE ROTATE*/
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
