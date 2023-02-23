/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:24:24 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 02:52:36 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printerror(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

long int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	r;

	s = 1;
	r = 0;
	i = check(str);
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == '\0')
			ft_printerror("ERROR");
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		if (r * 10 + str[i] - 48 < r && s == -1)
			ft_printerror("ERROR");
		else if (r * 10 + str[i] - 48 < r && s == 1)
			ft_printerror("ERROR");
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * s);
}
