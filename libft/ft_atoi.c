/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:24:24 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/23 06:39:16 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printerror(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

static int	check1(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

static int	check2(char *str, int i, int *s)
{
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == '\0')
			ft_printerror("Error");
		if (str[i] == '-')
			*s = -(*s);
		i++;
	}
	return (i);
}

long int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	r;

	s = 1;
	r = 0;
	i = check1(str);
	i = check2(str, i, &s);
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		if (r * 10 + str[i] - 48 < r && s == -1)
			ft_printerror("Error");
		else if (r * 10 + str[i] - 48 < r && s == 1)
			ft_printerror("Error");
		r = r * 10 + str[i] - 48;
		i++;
	}
	if (str && (str[i] == '-' || str[i] == '+'))
		ft_printerror("Error");
	return (r * s);
}
