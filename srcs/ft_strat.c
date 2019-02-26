/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:01:41 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:25:26 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/aicu.h"

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
		i++;
	}
	return (strat);
}
