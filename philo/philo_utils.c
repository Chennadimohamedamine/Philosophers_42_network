/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:24 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/20 20:47:49 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long	to_int(char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i++] - 48;
		if (r > MAXINT)
			return (2147483649);
	}
	return (r * s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_cleanup(int flag)
{
	if (flag == 1)
		ft_putstr_fd(ERRO_MUTEX, 2);
	else if (flag == 2)
		ft_putstr_fd(ERRO_THREAD, 2);
	ft_safe_destroy_mutex(NULL, true);
	ft_malloc(0, true, 0, NULL);
}

void	ft_safe_destroy_mutex(void *mtx, bool free)
{
	static void	*mutexs[1000];
	static int	index;
	int			i;

	if (free)
	{
		i = 0;
		while (mutexs[i])
			ft_mutex(mutexs[i++], DESTORTY);
		index = 0;
		mutexs[index] = NULL;
		return ;
	}
	mutexs[index++] = mtx;
	mutexs[index] = NULL;
}
