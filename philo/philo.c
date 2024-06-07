/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/06/03 20:47:29 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *function_philo(void *p)
{
    t_pilo *philo;

    philo = (t_pilo *)p;
    usleep(philo->time_to_eat);
    ft_print_(philo->Philosopher," philo take the fork\n");
    usleep(philo->time_to_sleep);
    ft_print_(philo->Philosopher," philo is sleep\n");
    pthread_mutex_lock
    return (NULL);
}
void execute_program(t_pilo *philo)
{
    pthread_t t[philo->allphilo];
    int i;
    int handling_error;

    i = 0;
    while(i <= philo->allphilo)
    {
        handling_error = pthread_create(&t[i],NULL,&function_philo,philo);
        if (handling_error)
            failure_thread(i, " ==>  Error: pthread_create() failed\n");
        i++;
    }
    i = 0;
    while(i <= philo->allphilo)
    {
        handling_error = pthread_join(t[i],NULL);
        if (handling_error)
            failure_thread(i," ==>  Error: pthread_join() failed\n");
        i++;
    }
}

int main(int ac, char **av)
{
    t_pilo  philo;
    
    check(ac, av);
    philo.allphilo = to_int(av[1]);
    philo.time_to_dead = to_int(av[2]);
    philo.time_to_eat = to_int(av[3]);
    philo.time_to_sleep = to_int(av[4]);
    if (ac == 6)
        philo.number_of_times = to_int(av[5]);
    else
        philo.number_of_times = -1;
    execute_program(&philo);
    return (0);
}
