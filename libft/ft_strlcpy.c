/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:29:58 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/22 06:50:43 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	srcsize;
	int	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srcsize);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
