/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:25:52 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:30:21 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../includes/aicu.h"

void	ft_result(int result)
{
	if (result == 1)
		ft_putstr("\033[0;32mYou WON! :)\n");
	else
		ft_putstr("\033[0;31mYou LOST :'(\033[0m\n");
}

int		ft_error(char *to_free)
{
	if (to_free != NULL)
		free(to_free);
	ft_putstr("ERROR\n");
	return (0);
}

int		main(int argc, char **argv)
{
	char	*board;
	int		*tab;
	int		*strat;

	if (argc > 2)
		return (ft_error(NULL));
	if (argc == 2)
		board = ft_check_arg(argv[1]);
	else
		board = ft_get_arg();
	tab = malloc_buff(board);
	if (tab == NULL)
		return (ft_error(board));
	strat = ft_strat(tab);
	ft_result(ft_play(tab, strat));
	free(board);
	free(strat);
	free(tab);
	return (0);
}
