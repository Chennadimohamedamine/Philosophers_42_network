/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:27 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/15 23:31:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
void more_check(char *s)
{
    int i;
    
    i = 0;
    while (s[i] == ' ')
        i++;
    if (!s[i])
        ft_perror("OPS! you have  invalid argument [enter just number]\n");
    else if (s[i] == '-')
        ft_perror("OPS! you have  invalid argument [the number can not be negative ]\n");
    else if ((s[i] == '+' && (!s[i + 1] || !(s[i + 1] >= '0' && s[i + 1] <= '9'))))
        ft_perror("OPS! you have  invalid argument [enter just valid number]\n");
    else if (s[i] == '+')
        i++;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
                ft_perror("OPS! you have  invalid argument [enter just number]\n");
        i++;
    }
}
void check(int ac, char **av)
{
    int i;
    long r;

    if (ac != 5 && ac != 6)
        ft_perror("OPS! you have  invalid argument\n");
    i = 1;
    while (i < ac)
    {
        if (!av[i][0])
            ft_perror("OPS! you have  invalid argument [ the string is emty ]\n");
        more_check(av[i]);
        r = to_int(av[i]);
        if (r < MININT || r > MAXINT)
            ft_perror("OPS! you have  invalid argument [you have agument geart max or less min int ]\n");
        i++;
    }
}
