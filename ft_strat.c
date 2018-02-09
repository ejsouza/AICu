/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:01:41 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/04 17:34:30 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int	*ft_strat(int *tab)
{
	int *strat;
	int i;

	i = 0;
	while (tab[i] > 0)
		i++;
	strat = malloc(i * sizeof(int));
	strat[i - 1] = -1;
	i = 1;
	strat[0] = 1;
	while (tab[i] > 0)
	{
		if (tab[i - 1] % 4 == 1 && strat[i - 1] == 0)
			strat[i] = 1;
		if (tab[i - 1] % 4 == 1 && strat[i - 1] == 1)
			strat[i] = 0;
		else if (tab[i - 1] % 4 != 1 && strat[i - 1] == 0)
			strat[i] = 0;
		else if (tab[i - 1] % 4 != 1 && strat[i - 1] == 1)
			strat[i] = 1;
		i = i + 1;
	}
	return (strat);
}
