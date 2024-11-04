/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:23:30 by mochenna          #+#    #+#             */
/*   Updated: 2024/11/03 15:20:00 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	ft_write(philo, EAT);
	ft_sleep(philo->data->time_eat, philo);
	sem_wait(philo->data->sem_meals);
	philo->last_meal_time = gettime();
	philo->meals_eaten++;
	if (philo->meals_eaten != philo->data->meals)
		philo->data->full_philos++;
	sem_post(philo->data->sem_meals);
}

bool	ft_hold_forks(t_philo *philo)
{
	sem_wait(philo->data->sem_forks);
	ft_write(philo, FORK);
	sem_wait(philo->data->sem_forks);
	ft_write(philo, FORK);
	return (true);
}

bool	ft_put_forks(t_philo *philo)
{
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
	return (true);
}

bool	end_nbrphilo(t_philo *philo)
{
	sem_wait(philo->data->sem_death);
	philo->data->is_finish = true;
	philo->data->end_similation = true;
	printf("%ld %d died\n",
		gettime() - philo->data->start_similation, philo->id);
	sem_post(philo->data->sem_death);
	sem_post(philo->data->sem_forks);
	exit(1);
}

void	ft_lifesycle(t_philo *philo)
{
	pthread_t	death_thread;

	pthread_create(&death_thread, NULL, death_checker, philo);
	pthread_detach(death_thread);
	while (1337)
	{
		if (is_dead(philo))
			exit(1);
		sem_wait(philo->data->sem_forks);
		ft_write(philo, FORK);
		sem_wait(philo->data->sem_forks);
		ft_write(philo, FORK);
		ft_eat(philo);
		sem_post(philo->data->sem_forks);
		sem_post(philo->data->sem_forks);
		ft_write(philo, SLEEP);
		ft_sleep(philo->data->time_sleep, philo);
		ft_write(philo, THINK);
		if (if_full(philo))
			exit(1);
	}
}
