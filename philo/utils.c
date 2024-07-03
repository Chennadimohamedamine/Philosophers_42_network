/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/03 19:36:23 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	to_int(char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i++] - 48;
        if (r > MAXINT)
            return (2147483649);
	}
	return (r * s);
}
void convert_to_microseconds(t_philo *philo)
{
	philo->time.dead = philo->time_to_dead * microseconds;
	philo->time.eat = philo->time_to_eat * microseconds;
	philo->time.sleep = philo->time_to_sleep * microseconds;
	philo->time.think = philo->time_to_think * microseconds;
}
// static void asignfork(t_philo *philo)
// {
// 	int i;

// 	i = -1;
// 	while (++i < philo->allphilo)
// 	{
// 		philo->philo[i]->fork->fork_right = i;
// 		if (i == 0)
// 			philo->philo[i]->fork->fork_left = philo->allphilo;
// 		else
// 			philo->philo[i]->fork->fork_left = i + 1;
// 	}
// }
int init_philosopher(t_philo *philo)
{
	int i;
	
	philo->philo = (struct s_ph *)malloc(philo->allphilo * sizeof(struct s_ph));
    if (!philo->philo)
        return(1);
	i = -1;
	while (++i < philo->allphilo)
	{
		philo->philo[i].id = i;
		philo->philo[i].fork.fork_right = i;
		if (i == philo->allphilo  - 1)
			philo->philo[i].fork.fork_left = 0;
		else
			philo->philo[i].fork.fork_left = i + 1;
		printf("id for thread ==> %d\n",philo->philo[i].id + 1);
		printf(BLUE_TEXT"id for right fork ==> %d\n"RESET_COLOR,philo->philo[i].fork.fork_right);
		printf(RED_TEXT"id for left fork ==> %d\n"RESET_COLOR,philo->philo[i].fork.fork_left);
	}
	return 0;
}