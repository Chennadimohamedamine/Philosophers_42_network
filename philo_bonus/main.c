/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:45:17 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/15 16:41:03 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
    t_share arg;
    if (!ft_check_data(ac, av, &arg))
    {
        printf("start the program\n");
    }
    else
        return (1);
    return (0);
}