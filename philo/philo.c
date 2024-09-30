/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/01 00:52:36 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void printdata(t_data *d)
{
    printf(">>>>>>>>================ { print data } =====================<<<<<<<<<<<<<<\n");
    printf("all the philosopher is %d\n",d->philosophers);
    printf("time to eat is %d\n",d->time_to_eat);
    printf("time to think is %d\n",d->time_to_think);
    printf("time to sleep is %d\n",d->time_to_sleep);
    printf("time to dead is %d\n",d->time_to_dead);
    if (d->meals == -1337)
        printf("we dont have any meals\n");
    else
        printf("time to meals is %d\n",d->meals);
    printf(">>>>>>>>================ { time } =====================<<<<<<<<<<<<<<\n");
    printf("time to eat in microsecend is %lu\n",d->time.eat);
    printf("time to think in microsecend is %lu\n",d->time.think);
    printf("time to sleep in microsecend is %lu\n",d->time.sleep);
    printf("time to dead in microsecend is %lu\n",d->time.dead);
}
void   int_philosophers(t_data *data ,t_philo * philo, t_fork *forks, int id)
{
        philo->is_dead = false;
        philo->id = id;
        philo->meals_counter = 0;
        philo->fork_right = &forks[id];
        philo->fork_left = &forks[(id + 1) % data->philosophers];
        if (id % 2)
        {
            philo->fork_left = &forks[id];
            philo->fork_right = &forks[(id + 1) % data->philosophers];
        }
        philo->data = data;
}
bool    init(t_data *data, int i)
{
    data->fork = ft_malloc((sizeof(t_fork) * data->philosophers), data);
    if (data->malloc_failure == true)
    data->philo = ft_malloc((sizeof(t_philo) * data->philosophers), data);
    if (data->malloc_failure == true)
        return (ft_putstr_fd(MALLOC_FAILURE, 2), true);
    while (++i < data->philosophers)
    {
        ft_mutex(&data->fork[i].fork, INIT);
        data->fork[i].fork_id = i;
    }
    while (++i < data->philosophers)
        int_philosophers(data, &data->philo[i], data->fork, i);
    return (false);
}

bool init_data(int ac, char **av, t_data *philo)
{
    if (checker(ac, av))
        return (true);
    philo->philosophers = to_int(av[1]);
    philo->time_to_dead = to_int(av[2]);
    philo->time_to_eat = to_int(av[3]);
    philo->time_to_sleep = to_int(av[4]);
    if (philo->philosophers == 0)
        return (ft_putstr_fd("Error [you can not run with 0 philosopher]\n", 2),1);
    else if (philo->philosophers > 200)
        return (ft_putstr_fd("Do not test with more than 200 philosophers\n",2),1);
    else if (philo->time_to_dead < MILSECOND || philo->time_to_eat < MILSECOND
        || philo->time_to_sleep < MILSECOND )
        return (ft_putstr_fd("Do not test values lower than 60 ms \n",2),1);
    if (ac == 6)
        philo->meals = to_int(av[5]);
    else
        philo->meals = -1337;
    philo->time.dead = philo->time_to_dead * MICROSECONDS;
	philo->time.eat = philo->time_to_eat * MICROSECONDS;
	philo->time.sleep = philo->time_to_sleep * MICROSECONDS;
    philo->malloc_failure = false;
    philo->all_thread_run = false;
    philo->conter = 0;
    philo->is_out = false;
    return (init(philo, -1));
}
int main(int ac, char **av)
{
    t_data  philo;
    if (init_data(ac, av, &philo))
        return (1);
    if (philo.malloc_failure == true)
        return (1);
    printf(">>>============ excute the program ================<<<\n");
    return (0);
}
