/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:27 by mochenna          #+#    #+#             */
/*   Updated: 2024/09/29 16:53:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool valid_input(char *s)
{
    int i;

    i = 0;
    while (s[i] == ' ')
        i++;
    if (!s[i])
        return (ft_putstr_fd(ERRO_NUM, 2), true);
    else if (s[i] == '-')
        return (ft_putstr_fd(ERRO_NNUM, 2), true);
    else if ((s[i] == '+' && (!s[i + 1] || !(s[i + 1] >= '0' && s[i + 1] <= '9'))))
        return (ft_putstr_fd(ERRO_VNUM, 2), true);
    else if (s[i] == '+')
        i++;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (ft_putstr_fd(ERRO_DNUM, 2), true);
        i++;
    }
    return (false);
}
bool checker(int ac, char **av)
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
    return (false);
}
