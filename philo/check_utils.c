/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:27 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/02 19:17:14 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
int more_check(char *s)
{
    int i;

    i = 0;
    while (s[i] == ' ')
        i++;
    if (!s[i])
        return (printf("OPS! you have  invalid argument [enter just number]\n"), 1);  
    else if (s[i] == '-')
        return (printf("OPS! you have  invalid argument [the number can not be negative]\n"), 1);
    else if ((s[i] == '+' && (!s[i + 1] || !(s[i + 1] >= '0' && s[i + 1] <= '9'))))
        return (printf("OPS! you have  invalid argument [enter just valid number]\n"), 1);
    else if (s[i] == '+')
        i++;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (printf("OPS! you have  invalid argument [enter just number digit]\n"), 1);  
        i++;
    }
    return (0);
}
int check(int ac, char **av)
{
    int i;
    long r;

    if (ac != 5 && ac != 6)
        return (printf("OPS! you have  invalid argument \n"), 1);
    i = 1;
    while (i < ac)
    {
        if (!av[i][0])
            return (printf("OPS! you have  invalid argument [ the string is emty]\n"), 1);
        if (more_check(av[i]))
            return (1);
        r = to_int(av[i]);
        if (r < MININT || r > MAXINT)
             return (printf("OPS! you have  invalid argument [you have agument geart max or less min int]\n"), 1);
        i++;
    }
    return (0);
}
