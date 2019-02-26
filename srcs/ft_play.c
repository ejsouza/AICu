/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:25:36 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:23:23 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/aicu.h"

void	ft_print_board(int *tab)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (tab[i] > 0)
	{
		tmp = tab[i];
		while (tmp > 0)
		{
			ft_putstr("\033[4;33m|\033[0m");
			tmp--;
		}
		ft_putstr("\n");
		i++;
	}
}

int		ft_get_val(int nb_al)
{
	char	*tmp;
	int		ret;

	ft_putstr("\033[1;32mChoose the amount of matches");
	ft_putstr("\033[1;32m you want to get\033[0m\n");
	get_next_line(1, &tmp);
	while (ft_atoi(tmp) > 3 || ft_atoi(tmp) < 1
			|| ft_atoi(tmp) > nb_al)
	{
		if (ft_atoi(tmp) > 3 || ft_atoi(tmp) < 1)
			ft_putstr("\033[1;36mPlease enter a value between 1 and 3\n");
		if (ft_atoi(tmp) > nb_al)
		{
			ft_putstr("\033[0;31mThere aren't that ");
			ft_putstr("many matches on this line\n");
		}
		free(tmp);
		get_next_line(1, &tmp);
	}
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

int		ft_ai(int length, int *strat, int *tab)
{
	int ret;

	if (strat[length] == 1)
		ret = tab[length] % 4 - 1;
	else
		ret = tab[length] % 4;
	if (ret == -1)
		ret = 3;
	if (ret == 0)
		ret = 2;
	ft_putstr("\033[1;34mThe computer takes ");
	ft_putchar('0' + ret);
	ft_putstr(" matche(s) off the board\n");
	return (ret);
}

int		ft_play(int *tab, int *strat)
{
	int length;

	length = 0;
	while (tab[length] > 0)
		length++;
	length--;
	while (tab[0] > 0)
	{
		while (tab[length] > 0)
		{
			ft_print_board(tab);
			tab[length] = tab[length] - ft_get_val(tab[length]);
			if (tab[length] == 0 && length > 0)
				length--;
			else if (tab[length] == 0)
				return (0);
			if (length >= 0)
			{
				ft_print_board(tab);
				tab[length] = tab[length] - ft_ai(length, strat, tab);
			}
		}
		length--;
	}
	return (1);
}
