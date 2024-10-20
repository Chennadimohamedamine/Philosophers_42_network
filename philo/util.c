/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:46:47 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/20 20:47:18 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	ft_init_mutexs(t_data *data, t_share *arg, t_mtx *forks)
{
	int	i;

	i = -1;
	while (++i < arg->nbr_philo)
	{
		if (ft_mutex(&forks[i], INIT))
			return (ft_cleanup(1), true);
		ft_safe_destroy_mutex(&forks[i], false);
	}
	if (ft_mutex(&data->stop_mtx, INIT))
		return (ft_cleanup(1), true);
	ft_safe_destroy_mutex(&data->stop_mtx, false);
	if (ft_mutex(&data->print, INIT))
		return (ft_cleanup(1), true);
	ft_safe_destroy_mutex(&data->print, false);
	if (ft_mutex(&data->monitor, INIT))
		return (ft_cleanup(1), true);
	ft_safe_destroy_mutex(&data->monitor, false);
	if (ft_mutex(&data->meals, INIT) == -1337)
		return (ft_cleanup(1), true);
	ft_safe_destroy_mutex(&data->meals, false);
	return (false);
}
