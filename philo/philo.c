/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/14 17:53:02 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void check(int ac, char **av)
{
    int i;
    int j;
    long r;

    if (ac != 5 && ac != 6)
        ft_perror("OPS! you have  invalid argument\n");
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9') && av[i][0] != '+')
                ft_perror("OPS! you have  invalid argument [enter just number]\n");
            j++;
        }
        r = to_int(av[i]);
        if (r < MININT || r > MAXINT)
            ft_perror("OPS! you have  invalid argument [you have agument geart max or less min int ]\n");
        i++;
    }
}
int main(int ac, char **av)
{
    check(ac, av);
    printf("=========> all good [ start you code ]  <====================\n");
    return (0);
}