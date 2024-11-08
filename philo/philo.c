/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/11/03 15:11:26 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	ft_allocat_data(t_philo **philo, t_mtx **forks, t_share arg)
{
	(*forks) = (t_mtx *)
		ft_malloc(sizeof(t_mtx) * arg.nbr_philo, false, 1337, NULL);
	if (!(*forks))
		return (true);
	(*philo) = (t_philo *)
		ft_malloc(sizeof(t_philo) * arg.nbr_philo, false, 1337, NULL);
	if (!(*philo))
		return (true);
	return (false);
}

bool	init_data(t_data *data, t_share *arg, t_philo *philo, t_mtx *forks)
{
	int	i;

	if (ft_init_mutexs(data, arg, forks))
		return (true);
	i = -1;
	data->end_similation = false;
	data->start_similation = gettime();
	data->full_philos = 0;
	while (++i < arg->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].arg = arg;
		philo[i].is_dead = data;
		philo[i].last_meals_time = gettime();
		philo[i].meals_counter = 0;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % arg->nbr_philo];
		philo[i].is_finish = false;
	}
	return (false);
}

void	*ft_lifesycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->arg->time_eat, philo);
	while (1337)
	{
		if (is_dead(philo))
			break ;
		if (ft_hold_forks(philo))
			return (NULL);
		ft_eat(philo);
		if (ft_mutex(philo->left_fork, UNLOCK))
			return (NULL);
		if (ft_mutex(philo->right_fork, UNLOCK))
			return (NULL);
		ft_write(philo, SLEEP);
		ft_sleep(philo->arg->time_sleep, philo);
		ft_write(philo, THINK);
	}
	return (NULL);
}

void	ft_run_thread(t_philo *philo, t_share *arg)
{
	int	i;

	if (ft_thread(&arg->monitor, ft_monitor, philo, CREATE))
		return ;
	i = -1;
	while (++i < arg->nbr_philo)
	{
		if (ft_thread(&philo[i].id_thread, ft_lifesycle, &philo[i], INIT))
			return ;
	}
	if (ft_thread(&arg->monitor, NULL, NULL, JOIN))
		return ;
	i = -1;
	while (++i < arg->nbr_philo)
	{
		if (ft_thread(&philo[i].id_thread, NULL, NULL, JOIN))
			return ;
	}
	ft_cleanup(1337);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;
	t_mtx	*forks;
	t_share	arg;

	if (!ft_check_data(ac, av, &arg))
	{
		if (arg.meals == 0)
			return (0);
		if (ft_allocat_data(&philo, &forks, arg))
			return (1);
		if (init_data(&data, &arg, philo, forks))
			return (1);
		ft_run_thread(philo, &arg);
	}
	else
		return (1);
	return (0);
}
