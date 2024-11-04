/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:37:43 by mochenna          #+#    #+#             */
/*   Updated: 2024/11/03 15:21:26 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

long	gettime(void)
{
	t_time	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (ft_putstr_fd(TIME_FAILURE, 2), -1337);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	ft_init_semaphores(t_data *data)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_MEALS);
	sem_unlink(SEM_DEATH);
	data->sem_forks
		= sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644, data->nbr_philo);
	data->sem_print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, 0644, 1);
	data->sem_meals = sem_open(SEM_MEALS, O_CREAT | O_EXCL, 0644, 1);
	data->sem_death = sem_open(SEM_DEATH, O_CREAT | O_EXCL, 0644, 1);
	if (data->sem_forks == SEM_FAILED || data->sem_print == SEM_FAILED
		|| data->sem_meals == SEM_FAILED || data->sem_death == SEM_FAILED)
		return (0);
	return (1);
}
