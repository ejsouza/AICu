/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:35:12 by esouza            #+#    #+#             */
/*   Updated: 2018/02/04 22:12:58 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		count_line_feed(char *s)
{
	size_t		i;
	int			lines;

	i = 0;
	lines = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int				check_buff(char *s)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = ft_strlen(s);
	while ((s[i] != '\0') && ((s[i] >= '0' && s[i] <= '9') || s[i] == '\n'))
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
		i++;
	}
	return (size == i);
}

int				*ft_fail(int *tab)
{
	free(tab);
	return (NULL);
}

int				*malloc_buff(char *s)
{
	int			i;
	int			index;
	int			*tab;

	if (check_buff(s) == 0)
		return (NULL);
	i = 0;
	index = 1;
	if (!(tab = (int *)malloc(sizeof(int) * (count_line_feed(s) + 1))))
		return (NULL);
	if ((tab[0] = ft_atoi(s)) < 1 || ft_atoi(s) > 10000)
		return (ft_fail(tab));
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == '\n' && s[i + 1] != '\0')
		{
			tab[index] = ft_atoi(s + i);
			if (tab[index] < 1 || tab[index] > 10000)
				return (ft_fail(tab));
			index++;
		}
	}
	tab[index] = -1;
	return (tab);
}
