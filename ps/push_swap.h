/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:34:54 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 05:43:19 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "unistd.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_index
{
	int		i;
	int		j;
}			t_index;

typedef struct s_array
{
	t_index	index;
	int		*t;
	int		size;
	int		swap;
}			t_array;

typedef struct s_informations
{
	int		mid;
	int		offset;
	int		div;
	int		start;
	int		end;
	int		place;
}			t_info;

/*BEGGIN*/
void		check_args(char **glob);
char		**join_args(int ac, char *av[]);
t_list		*to_stack(char **glob);
void		which_function(t_list **a, t_list **b);
/*ACT00*/
/*instructions*/
void		swap(t_list *h, char *s);
void		swap_both(t_list *a, t_list *b);
void		push(t_list **from, t_list **to, char *s);
void		rotate(t_list **h, char *s);
void		rotate_both(t_list **a, t_list **b);
/*ACT01*/
/*instructions and check*/
void		reverse_rotate(t_list **h, char *s);
void		reverse_rotate_both(t_list **a, t_list **b);
void		printerror(char *s);
int			is_sorted(t_list *a);
int			is_not_empty(t_list *a, t_array array, t_info info);
/*ACT02*/
/*help large*/
t_info		get_info(t_array array);
int			get_place(t_list *a, int data, t_info info);
int			max_of_b(t_list *b);
int			get_index(t_array array, int data);
void		index_stack(t_list **stack, t_array array);
/*SORT*/
/*all about three five and free*/
int			the_max(t_list *stack);
int			the_min(t_list *stack);
void		sort_three(t_list **a);
void		sort_five(t_list **a, t_list **b);
void		free_all(char **glob);
/*LARGE*/
t_array		creat_sort_array(t_list *a);
void		first_push(t_list **a, t_list **b, t_array array, t_info info);
int			search_next(t_list *stack, int index);
void		push_back(t_list **a, t_list **b, int size);
void		large_sort(t_list **a, t_list **b);

#endif
