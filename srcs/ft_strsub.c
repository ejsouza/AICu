/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:27 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:28:19 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/aicu.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char*)(malloc((len + 1) * sizeof(char)))))
		return (NULL);
	else
	{
		while (i < len)
		{
			new[i] = s[i + start];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
}
