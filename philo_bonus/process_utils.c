/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:23:30 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/20 01:41:51 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_eat(t_philo *philo)
{
    ft_write(philo, EAT);
    ft_sleep(philo->data->time_eat, philo);
    sem_wait(philo->data->sem_meals);
    philo->last_meal_time = gettime();
    philo->meals_eaten++;
    if (philo->meals_eaten !=  philo->data->meals)
        philo->data->full_philos++;
    sem_post(philo->data->sem_meals);
}