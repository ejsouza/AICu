/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:20:08 by esouza            #+#    #+#             */
/*   Updated: 2018/02/04 16:53:35 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int	ft_suite(const char *str, int i, int debut, long nbr)
{
	long	tmp;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i = i + 1;
	debut = i;
	tmp = nbr;
	while (str[i] && nbr >= tmp)
	{
		tmp = nbr;
		if ((!(ft_isdigit(str[i])) && str[i] != '+' && str[i] != '-')
				|| (str[i] == '+' && i != debut)
				|| (str[i] == '-' && i != debut))
			i = ft_strlen(str);
		if (str[i] >= '0' && str[i] <= '9')
			nbr = (long)(10 * nbr + str[i] - '0');
		if (str[i])
			i = i + 1;
	}
	if (tmp > nbr)
		return (str[debut] == '-' ? 0 : -1);
	if (str[debut] == '-')
		return ((int)(-nbr));
	return (nbr);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		debut;
	long	nbr;

	i = 0;
	debut = 0;
	nbr = 0;
	return (ft_suite(str, i, debut, nbr));
}
