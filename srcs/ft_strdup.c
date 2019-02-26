/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:41:04 by vburidar          #+#    #+#             */
/*   Updated: 2019/02/26 15:26:33 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/aicu.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	if ((new_str = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		while (s[i])
		{
			new_str[i] = s[i];
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	else
		return (NULL);
}
