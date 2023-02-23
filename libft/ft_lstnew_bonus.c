/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:18:36 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/20 09:37:38 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int data)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	return (n);
}
