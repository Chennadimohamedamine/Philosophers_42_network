/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:37:35 by mochenna          #+#    #+#             */
/*   Updated: 2024/11/03 15:21:47 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	ft_init_data(t_data *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal_time = gettime();
		philo[i].data = arg;
		i++;
	}
	arg->start_similation = gettime();
	arg->end_similation = false;
	arg->ready_count = 0;
	arg->full_philos = 0;
	arg->is_finish = false;
	if (!ft_init_semaphores(arg))
		return (ft_putstr_fd("Error: failed to create semaphores\n", 2), true);
	return (false);
}

void	ft_start_simulation(t_data *data, t_philo *philo)
{
	int	i;
	int	status;

	i = -1;
	while (++i < data->nbr_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
		{
			ft_clean(data, -1337);
			return ;
		}
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
}

int	main(int ac, char **av)
{
	t_data	arg;
	t_philo	*philo;

	if (!ft_check_data(ac, av, &arg))
	{
		philo = (t_philo *)
			ft_malloc(sizeof(t_philo) * arg.nbr_philo, false, 1337, NULL);
		if (!philo)
			return (1);
		if (ft_init_data(&arg, philo))
			return (1);
		ft_start_simulation(&arg, philo);
	}
	else
		return (1);
	return (0);
}
