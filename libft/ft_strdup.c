/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:18:42 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/20 20:42:09 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*t;
	int		i;

	i = 0;
	t = malloc(ft_strlen(src) + 1);
	if (!t)
		return (NULL);
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
