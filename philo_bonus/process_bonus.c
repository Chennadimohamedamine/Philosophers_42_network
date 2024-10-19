/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:37:40 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/19 16:39:25 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	is_dead(t_philo *philo)
{
	sem_wait(philo->data->sem_death);
	if (philo->data->end_similation == true)
	{
        sem_post(philo->data->sem_death);
		return (true);
	}
    sem_post(philo->data->sem_death);
	return (false);
}
void    *death_checker(void *arg)
{
    t_philo     *philo;
    long long   current_time;

    philo = (t_philo *)arg;
    while (1)
    {
        sem_wait(philo->data->sem_death);
        current_time = gettime();
        if (current_time - philo->last_meal_time > philo->data->time_die)
        {
            printf("%lld %d died\n", current_time - philo->data->start_similation, philo->id);
            philo->data->end_similation = true;
            exit(1);
        }
        sem_post(philo->data->sem_death);
        usleep(100);
    }
    return (NULL);
}

void ft_sleep(long mls, t_philo *philo)
{
	long start;

	start = gettime();
	while ((gettime() - start) < mls)
	{
        sem_wait(philo->data->sem_death);
		if (philo->data->end_similation)
		{
            sem_post(philo->data->sem_death);
			return;
		}
        sem_post(philo->data->sem_death);
		usleep(100);
	}
}
void	ft_write(t_philo *philo, int flag)
{
	long	time;

	if (is_dead(philo))
		return ;
	sem_wait(philo->data->sem_print);
	time = gettime() - philo->data->start_similation;
	if (flag == FORK)
		printf("%ld %d has taken a fork\n", time, philo->id);
	else if (flag == EAT)
		printf("%ld %d is eating \n", time, philo->id);
	else if (flag == SLEEP)
		printf("%ld %d is sleeping\n", time, philo->id);
	else if (flag == THINK)
		printf("%ld %d is thinking\n", time, philo->id);
	sem_post(philo->data->sem_print);
}
bool if_full(t_philo *philo)
{
    if (philo->data->meals != -1337)
    {
        sem_wait(philo->data->sem_meals);
        if (philo->meals_eaten == philo->data->nbr_philo)
        {
            sem_post(philo->data->sem_meals);
            sem_wait(philo->data->sem_death);
            philo->data->end_similation = true;
            sem_post(philo->data->sem_death);
            return (true);
        }
        sem_post(philo->data->sem_meals);
    }
    return (false);
}
void ft_lifesycle(t_philo *philo)
{
    pthread_t death_thread;

    pthread_create(&death_thread, NULL, death_checker, philo);
    pthread_detach(death_thread);
    while (1337)
    {
        if (is_dead(philo))
            break ;
        sem_wait(philo->data->sem_forks);
        ft_write(philo, FORK);
        sem_wait(philo->data->sem_forks);
        ft_write(philo, FORK);
        ft_write(philo, EAT);
        ft_sleep(philo->data->time_eat, philo);
        sem_wait(philo->data->sem_meals);
        philo->last_meal_time = gettime();
        if (philo->data->meals != -1337)
            philo->meals_eaten++;
        sem_post(philo->data->sem_meals);
        sem_post(philo->data->sem_forks);
        sem_post(philo->data->sem_forks);
        ft_write(philo, SLEEP);
        ft_sleep(philo->data->time_sleep, philo);
        ft_write(philo, THINK);
        if (if_full(philo))
            break ;
    }
}
