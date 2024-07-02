/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/02 18:39:47 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
        if (r > MAXINT)
            return (2147483649);
	}
	return (r * s);
}
char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		l;
	int		i;

	l = 0;
	while(s1[l])
		l++;
	i = 0;
	cpy = (char *)malloc(sizeof(char) * l + 1);
	if (cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
int ft_strcmp(char *s, char *s1)
{
	int i;

	i = 0;
	while (s[i] && s1[i] && s[i] != s1[i])
		i++;
	return (s[i] - s1[i]);
}
// void out_exe(t_philo *philo)
// {
// 	free(philo->Philosoph.id);	
// 	free(philo->Philosoph.handling_error);	
// }