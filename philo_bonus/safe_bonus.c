/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:48:29 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool ft_parc_digit(t_share *arg, char **av, int ac)
{
    arg->nbr_philo = to_int(av[1]);
    arg->time_dead = to_int(av[2]);
    arg->time_eat = to_int(av[3]);
    arg->time_sleep = to_int(av[4]);
    if (arg->nbr_philo == 0)
        return (ft_putstr_fd("Error [you can not run with 0 philosopher]\n", 2), true);
    else if (arg->nbr_philo > 200)
        return (ft_putstr_fd("Do not test with more than 200 philosophers\n", 2), true);
    else if (arg->time_dead < MILSECOND || arg->time_eat < MILSECOND || arg->time_sleep < MILSECOND)
        return (ft_putstr_fd("Do not test values lower than 60 ms \n", 2), true);
    if (ac == 6)
    {
        arg->meals = to_int(av[5]);
        if (arg->meals <= 0)
            return (ft_putstr_fd("Do not test values lower than 0 in meals \n", 2), true);
    }
    else
        arg->meals = -1337;
    return (false);
}

bool valid_input(char *s)
{
    int i;
    int len;

    i = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    len = ft_strlen(s) - 1;
    while (s[len] == ' ' || (s[len] >= 9 && s[len] <= 13))
        len--;
    if (!s[i])
        return (ft_putstr_fd(ERRO_NUM, 2), true);
    else if (s[i] == '-')
        return (ft_putstr_fd(ERRO_NNUM, 2), true);
    else if ((s[i] == '+' && (!s[i + 1] || !(s[i + 1] >= '0' && s[i + 1] <= '9'))))
        return (ft_putstr_fd(ERRO_VNUM, 2), true);
    else if (s[i] == '+')
        i++;
    while (i <= len)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (ft_putstr_fd(ERRO_DNUM, 2), true);
        i++;
    }
    return (false);
}
bool ft_check_data(int ac, char **av, t_share *arg)
{
    int i;
    long r;

    if (ac != 5 && ac != 6)
        return (ft_putstr_fd(ERRO_INVARG, 2), true);
    i = 1;
    while (i < ac)
    {
        if (!av[i][0])
            return (ft_putstr_fd(ERRO_INVARGEMTY, 2), true);
        if (valid_input(av[i]))
            return (1);
        r = to_int(av[i]);
        if (r < MININT || r > MAXINT)
            return (ft_putstr_fd(ERRO_INVARG_NOT_INT, 2), true);
        i++;
    }
    if (ft_parc_digit(arg, av, ac))
        return (true);
    return (false);
}