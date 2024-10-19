/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:37:35 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/19 16:40:31 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool ft_start_simulation(t_data *data, t_philo *philo)
{
    int i;
    int status;

    i = -1;
    while (++i < data->nbr_philo)
    {
        philo[i].pid = fork();
        if (philo[i].pid < 0)
            return (ft_clean(data, -1337), true);
        if (philo[i].pid == 0)
        {
            ft_lifesycle(&philo[i]);
            exit(0);
        }
    }
    waitpid(-1, &status, 0);
    i = -1;
    while (++i < data->nbr_philo)
        kill(philo[i].pid, SIGKILL);
    ft_clean(data, 1337);
    return (true);
}
int main(int ac, char **av)
{
    t_data arg;
    t_philo *philo;

    if (!ft_check_data(ac, av, &arg))
    {
        philo = (t_philo *)ft_malloc(sizeof(t_philo) * arg.nbr_philo, false, 1337, NULL);
        if (!philo)
            return (1);
        if (ft_init_data(&arg, philo))
            return (1);
        if (ft_start_simulation(&arg, philo))
            return (1);
    }
    else
        return (1);
    return (0);
}
