/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/15 23:02:56 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_C
#define PHILOSOPHER_C

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

#define MAXINT 2147483647 
#define MININT -2147483648


void printstr(char *s);
long	to_int(char *str);
void ft_perror(char *s);
void check(int ac, char **av);

#endif