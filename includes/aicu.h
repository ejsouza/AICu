/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:01:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/04 15:34:50 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

# define BUFF_SIZE 16

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
**	LIBFT
*/
void	ft_memdel(void **ap);
char	*ft_strjoin(char const *s1, char const *s2, int i);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	*ft_memchr(const void *src, int c, size_t taille);
void	*ft_memmove(void *dest, const void *src, size_t taille);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dst, const char *src);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

/*
**	AICU
*/
char	*ft_check_arg(char *arg);
char	*ft_get_arg(void);
int		ft_play(int *tab, int *strat);
int		*malloc_buff(char *s);
int		*ft_strat(int *tab);

/*
** GET_NEX_LINE
*/
int		get_next_line(const int fd, char **line);
#endif
