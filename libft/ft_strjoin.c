/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:39:00 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 01:43:47 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
		s1 = ft_strdup("");
	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new_s)
		return (NULL);
	while (s1[i])
		new_s[c++] = s1[i++];
	i = 0;
	new_s[c++] = ' ';
	while (s2[i])
		new_s[c++] = s2[i++];
	new_s[c] = '\0';
	free(s1);
	return (new_s);
}
