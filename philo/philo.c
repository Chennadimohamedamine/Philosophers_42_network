/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/12 23:05:02 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool ft_allocat_data(t_philo **philo, t_mtx **forks, t_share arg)
{
    (*forks) = (t_mtx *)ft_malloc(sizeof(t_mtx) * arg.nbr_philo, false, 1337, NULL);
    if (!(*forks))
        return (true);
    (*philo) = (t_philo *)ft_malloc(sizeof(t_philo) * arg.nbr_philo, false, 1337, NULL);
    if (!(*philo))
        return (true);
    return (false);
}
bool init_data(t_data *data, t_share *arg, t_philo *philo, t_mtx *forks)
{
    int i;

    ft_init_mutexs(data, arg, forks);
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
    }
    return (false);
}
void leaks()
{
    system("leaks philo");
}
void *ft_monitor(void *arg)
{
    long passtime;
    int i;
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1337)
    {
        i = -1;
        while (++i < philo[0].arg->nbr_philo)
        {
            ft_mutex(&philo[0].data->monitor, LOCK);
            passtime = gettime() - philo[i].last_meals_time;
            if (passtime > philo[i].arg->time_dead)
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

void *ft_lifesycle(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        ft_sleep(philo->arg->time_eat);
    while (1337)
    {
        if (is_dead(philo))
            break;
        ft_hold_forks(philo);
        ft_eat(philo);
        ft_mutex(philo->left_fork, UNLOCK);
        ft_mutex(philo->right_fork, UNLOCK);
        ft_write(philo, SLEEP);
        ft_sleep(philo->arg->time_sleep);
        ft_write(philo, THINK);
    }
    return (NULL);
}
void ft_run_thread(t_philo *philo, t_share *arg)
{
    int i;
    long passtime;

    if (arg->nbr_philo == 1)
    {
        passtime = gettime() - philo[0].last_meals_time;
        ft_write(&philo[0], FORK);
        printf("%ld %d died\n", passtime, philo[0].id);
        return ;
    }
    i = -1;
    ft_thread(&arg->monitor, ft_monitor, philo, CREATE);
    while (++i < arg->nbr_philo)
    {
        ft_thread(&philo[i].id_thread, ft_lifesycle, &philo[i], INIT);
    }
    ft_thread(&arg->monitor, NULL, NULL, JOIN);
    i = -1;
    while (++i < arg->nbr_philo)
        ft_thread(&philo[i].id_thread, NULL, NULL, JOIN);
}
int main(int ac, char **av)
{
    t_data  data;
    t_philo *philo;
    t_mtx   *forks;
    t_share arg;

    if (!ft_check_data(ac, av, &arg))
    {
        if (ft_allocat_data(&philo, &forks, arg))
            return (1);
        if (init_data(&data, &arg, philo, forks))
            return (1);
        ft_run_thread(philo, &arg);
        ft_malloc(0, true, 0, NULL);
    }
    else
        return (1);
    return (0);
}
