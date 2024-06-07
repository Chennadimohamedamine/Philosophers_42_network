/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/06/03 16:22:16 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_perror(char *s)
{
	printf("%s",s);
    exit(1);
}
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
        if ((r * s) > MAXINT || (r * s) < MININT)
                return (2147483649);
	}
	return (r * s);
}