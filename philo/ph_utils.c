/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:42:33 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/12 23:02:28 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_write(t_philo *philo, int flag)
{
    long time;

    if (is_dead(philo) == true)
        return ;
    ft_mutex(&philo->data->print, LOCK);
    time = gettime() - philo->data->start_similation;
    if (flag == FORK)
        printf("%ld %d has taken a fork\n", time, philo->id);
    else if (flag == EAT)
        printf("%ld %d is eating \n", time, philo->id);
    else if (flag == SLEEP)
        printf("%ld %d is sleeping\n", time, philo->id);
    else if (flag == THINK)
        printf("%ld %d is thinking\n", time, philo->id);
    ft_mutex(&philo->data->print, UNLOCK);
}

void ft_hold_forks(t_philo *philo)
{
    ft_mutex(philo->left_fork, LOCK);
    ft_write(philo, FORK);
    ft_mutex(philo->right_fork, LOCK);    
    ft_write(philo, FORK);
}
void ft_eat(t_philo *philo)
{
    ft_write(philo, EAT);
    ft_sleep(philo->arg->time_eat);
    ft_mutex(&philo->data->monitor, LOCK);
    philo->last_meals_time = gettime();
    ft_mutex(&philo->data->monitor, UNLOCK);

    ft_mutex(&philo->data->meals, LOCK);
    if (philo->arg->meals != -1337)
    {
        philo->meals_counter += 1; // 4 3 1
        if (philo->meals_counter == philo->arg->meals)
            philo->data->full_philos += 1;
    }
    ft_mutex(&philo->data->meals, UNLOCK);
}
