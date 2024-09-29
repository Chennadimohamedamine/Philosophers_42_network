/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/09/29 18:05:48 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void printdata(t_data *d)
{printf(">>>>>>>>================ { print data } =====================<<<<<<<<<<<<<<\n");
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

void    init_philo(t_data *data)
{
    data->all_thread_run = false;
    data->conter = 0;
    data->is_out = false;
    data->malloc_failure = false;
    data->fork = ft_malloc((sizeof(t_fork) * data->philosophers), data);
    if (data->malloc_failure == true)
    {
        ft_putstr_fd(MALLOC_FAILURE, 2);
        return ;
    }
    data->philo = ft_malloc((sizeof(t_philo) * data->philosophers), data);
    if (data->malloc_failure == true)
    {
        ft_putstr_fd(MALLOC_FAILURE, 2);
        return ;
    }
    
}

bool init_data(int ac, char **av, t_data *philo)
{
    if (checker(ac, av))
        return (true);
    philo->philosophers = to_int(av[1]);
    philo->time_to_dead = to_int(av[2]);
    philo->time_to_eat = to_int(av[3]);
    philo->time_to_sleep = to_int(av[4]);
    philo->time_to_think = to_int(av[4]);
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
	philo->time.think = philo->time_to_think * MICROSECONDS;
    init_philo(philo);
    return (false);
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
