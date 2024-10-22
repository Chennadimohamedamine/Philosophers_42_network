/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/22 01:41:50 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	ft_parc_digit(t_share *arg, char **av, int ac)
{
	arg->nbr_philo = to_int(av[1]);
	arg->time_dead = to_int(av[2]);
	arg->time_eat = to_int(av[3]);
	arg->time_sleep = to_int(av[4]);
	if (arg->nbr_philo == 0)
		return (ft_putstr_fd
			("Error [you can not run with 0 philosopher]\n", 2), true);
	else if (arg->nbr_philo > 200)
		return (ft_putstr_fd
			("Do not test with more than 200 philosophers\n", 2), true);
	else if (arg->time_dead < MILSECOND
		|| arg->time_eat < MILSECOND || arg->time_sleep < MILSECOND)
		return (ft_putstr_fd
			("Do not test values lower than 60 ms \n", 2), true);
	if (ac == 6)
		arg->meals = to_int(av[5]);
	else
		arg->meals = -1337;
	return (false);
}

void	ft_sleep(long mls, t_philo *philo)
{
	long	start;

	start = gettime();
	while ((gettime() - start) < mls)
	{
		ft_mutex(&philo->data->stop_mtx, LOCK);
		if (philo->data->end_similation || philo->is_finish)
		{
			ft_mutex(&philo->data->stop_mtx, UNLOCK);
			return ;
		}
		ft_mutex(&philo->data->stop_mtx, UNLOCK);
		usleep(150);
	}
}

void	endsimilation(t_philo *philo)
{
	ft_mutex(&philo->data->stop_mtx, LOCK);
	philo->data->end_similation = true;
	ft_mutex(&philo->data->stop_mtx, UNLOCK);
}

bool	if_eat_all_meals(t_philo *philo)
{
	if (philo->arg->meals != -1337)
	{
		ft_mutex(&philo->data->meals, LOCK);
		if (philo->arg->nbr_philo == philo->data->full_philos)
		{
			ft_mutex(&philo->data->meals, UNLOCK);
			ft_mutex(&philo->data->stop_mtx, LOCK);
			philo->data->end_similation = true;
			ft_mutex(&philo->data->stop_mtx, UNLOCK);
			return (true);
		}
		ft_mutex(&philo->data->meals, UNLOCK);
	}
	return (false);
}

void	*ft_monitor(void *arg)
{
	long	passtime;
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1337)
	{
		i = -1;
		while (++i < philo[0].arg->nbr_philo)
		{
			ft_mutex(&philo[0].data->monitor, LOCK);
			passtime = gettime() - philo[i].last_meals_time;
			if (passtime > philo[i].arg->time_dead || philo[i].is_finish)
			{
				endsimilation(&philo[i]);
				printf("%ld %d died\n", passtime, philo[i].id);
				return (ft_mutex(&philo[0].data->monitor, UNLOCK), NULL);
			}
			ft_mutex(&philo[0].data->monitor, UNLOCK);
			if (if_eat_all_meals(&philo[i]))
				return (NULL);
		}
	}
	return (NULL);
}
