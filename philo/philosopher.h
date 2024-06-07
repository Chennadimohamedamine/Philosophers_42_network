/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/05/30 19:59:04 by mochenna         ###   ########.fr       */
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

typedef struct s_ph
{
    int allphilo;
    int Philosopher;
    int time_to_eat;
    int time_to_dead;
    int time_to_sleep;
    int number_of_times;
    struct timeval time;
    pthread_mutex_t mutex;
} t_pilo;

int *ft_philo(int n);


void ft_print_(int number,char *s);
void print_int(int n);
void printstr(char *s);

long	to_int(char *str);

void ft_perror(char *s);
void check(int ac, char **av);
void failure_thread(int i,char *s);


#endif