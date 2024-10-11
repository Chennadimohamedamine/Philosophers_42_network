/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:42:33 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/11 18:44:14 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_write(t_philo *philo, int flag)
{
    long time;
    
    ft_mutex(philo->data->print, LOCK);
    time = gettime() - philo->last_meals_time;
    if (flag == FORK)
        printf("%ld %d has taken a fork\n", time, philo->id);
    else if (flag == EAT)
        printf("%ld %d is eating \n", time, philo->id);
    else if (flag == SLEEP)
        printf("%ld %d is sleeping\n", time, philo->id);
    else if (flag == THINK)
        printf("%ld %d is thinking\n", time, philo->id);
    ft_mutex(philo->data->print, UNLOCK);
}

void ft_hold_forks(t_philo *philo)
{
    ft_mutex(philo->left_fork, LOCK);
    ft_write(philo, FORK);       
    ft_mutex(philo->right_fork, LOCK);    
    ft_write(philo, FORK);
}
