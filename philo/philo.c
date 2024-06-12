/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/06/12 15:41:38 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char  shadow_clone(t_philo *philo)
{
    int i;
    int handling_error;

    i = 0;
    while(i <= philo->allphilo)
    {
        handling_error = pthread_create(&t[i],NULL,&,philo);
        if (handling_error)
            return('j');
        i++;
    }
    i = 0;
    while(i <= philo->allphilo)
    {
        handling_error = pthread_join(t[i],NULL);
        if (handling_error)
           return('j');
        i++;
    }
}

int execute_program(t_philo *philo)
{
    pthread_t t[philo->allphilo];
    if (shadow_clone(&philo) == 'c')
        return (printf(" ==>  Error: pthread_create() failed\n"), 1);
    else if (shadow_clone(&philo) == 'j')
        return (printf(" ==>  Error: pthread_join() failed\n"), 1); 
}
int main(int ac, char **av)
{
    t_philo  philo;
    
    check(ac, av);
    philo.allphilo = to_int(av[1]);
    philo.time_to_dead = to_int(av[2]);
    philo.time_to_eat = to_int(av[3]);
    philo.time_to_sleep = to_int(av[4]);
    if (ac == 6)
        philo.number_of_times = to_int(av[5]);
    else
        philo.number_of_times = 0;
    
    if (execute_program(t_philo philo))
        return(1);    
    return (0);
}
