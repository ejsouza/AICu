/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:00:48 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/04 14:20:19 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
