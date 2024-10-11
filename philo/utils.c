/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/11 17:29:02 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool ft_parc_digit(t_share *arg, char **av, int ac)
{
    arg->nbr_philo = to_int(av[1]);
    arg->time_dead = to_int(av[2]);
    arg->time_eat = to_int(av[3]);
    arg->time_sleep = to_int(av[4]);
    if (arg->nbr_philo == 0)
        return (ft_putstr_fd("Error [you can not run with 0 philosopher]\n", 2), true);
    else if (arg->nbr_philo > 200)
        return (ft_putstr_fd("Do not test with more than 200 philosophers\n", 2), true);
    else if (arg->time_dead < MILSECOND || arg->time_eat < MILSECOND || arg->time_sleep < MILSECOND)
        return (ft_putstr_fd("Do not test values lower than 60 ms \n", 2), true);
    if (ac == 6)
        arg->meals = to_int(av[5]);
    else
        arg->meals = -1337;
    return (false);
}

long gettime(void)
{
    t_time current_time;

    if (gettimeofday(&current_time, NULL) != 0)
        return (ft_putstr_fd(TIME_FAILURE, 2), -1337);
    return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
void ft_sleep(long mls)
{
    long start;

    start = gettime();
    while ((gettime() - start) < mls)
        usleep(200);
}
void endsimilation(t_philo *philo)
{
    ft_mutex(&philo->data->mtx[0], LOCK);
    philo->data->end_similation = true;
    ft_mutex(&philo->data->mtx[0], UNLOCK);
}
bool if_eat_all_meals(t_philo *philo)
{
    if (philo->arg->meals != -1337)
    {
        ft_mutex(&philo->data->mtx[1], LOCK);
        if (philo->arg->meals == philo->meals_counter)
        {
             ft_mutex(&philo->data->mtx[1], UNLOCK);
            return (true);
        }
        ft_mutex(&philo->data->mtx[1], UNLOCK);
    }
    return (false);
}
void ft_init_mutexs(t_data *data, t_share *arg, t_mtx *forks)
{
    int i;

    i = -1;
    while (++i < arg->nbr_philo)
        ft_mutex(&forks[i], INIT);
    ft_mutex(&data->print, INIT);
    ft_mutex(&data->monitor, INIT);
    ft_mutex(&data->meals, INIT);
    i = 0;
    while (i < 4)
        ft_mutex(&data->mtx[i++], INIT);
}

bool if_dead(t_philo *philo)
{
    ft_mutex(&data->mtx[2], LOCK);  
    if (philo->data->end_similation == true)
    {
        ft_mutex(&data->mtx[2], UNLOCK);  
        return (true);
    }
    ft_mutex(&data->mtx[2], UNLOCK);  
    return (false);
}