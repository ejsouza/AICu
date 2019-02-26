/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:37:54 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:22:15 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/aicu.h"

char	*ft_check_arg(char *arg)
{
	int		fd;
	char	*board;
	char	*tmp;

	board = ft_strdup("");
	if ((fd = open(arg, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &tmp) == 1)
		{
			if (*board != '\0')
				board = ft_strjoin(board, "\n", 1);
			board = ft_strjoin(board, tmp, 3);
		}
		free(tmp);
	}
	return (board);
}

char	*ft_get_arg(void)
{
	char	*tmp;
	char	*board;

	board = ft_strdup("");
	while (get_next_line(0, &tmp) == 1)
	{
		if (*tmp == '\0')
		{
			board = ft_strjoin(board, "\n", 1);
			free(tmp);
			return (board);
		}
		if (*board != '\0')
			board = ft_strjoin(board, "\n", 1);
		board = ft_strjoin(board, tmp, 3);
	}
	free(tmp);
	return (board);
}
