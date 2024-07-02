/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/02 19:11:52 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


int init_philo(int ac, char **av,t_philo *philo)
{
    if (check(ac, av))
        return (1);
    philo->allphilo = to_int(av[1]);
    philo->time_to_dead = to_int(av[2]);
    philo->time_to_eat = to_int(av[3]);
    philo->time_to_sleep = to_int(av[4]);
    if (philo->allphilo == 0)
        return (printf("error [you can not run with 0 philosopher]\n"),1);
    else if (philo->allphilo > 200)
        return (printf("Do not test with more than 200 philosophers\n"),1);
    else if (philo->time_to_dead < milsecond || philo->time_to_eat < milsecond
        || philo->time_to_sleep < milsecond )
        return (printf("Do not test values lower than 60 ms \n"),1);
    if (ac == 6)
        philo->meals = to_int(av[5]);
    else
        philo->meals = -1;
    philo->flag_dead = false;
    return (0);
}
int main(int ac, char **av)
{
    t_philo  philo;

    if (init_philo(ac, av, &philo))
        return (1);
    // if (execute_program(&philo))
    //     return(1);
    return (0);
}
// simulation : currtime() - lst_meal > t2d --> 