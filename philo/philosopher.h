/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/02 19:18:53 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_C
#define PHILOSOPHER_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>

#define MAXINT 2147483647
#define MININT -2147483648
#define microseconds 1000
#define milsecond 60

typedef struct s_f
{
    pthread_mutex_t fork_mutex;
    int             fork_right;
    int             fork_left;
} t_fork;

typedef struct s_time
{
    struct timeval time;
    unsigned long current;
    unsigned long eat;
    unsigned long dead;
    unsigned long sleep;
    unsigned long think;
}t_time;

typedef struct s_ph
{
    unsigned long   allphilo;
    unsigned long   Philosopher;
    unsigned long   time_to_eat;
    unsigned long   time_to_dead;
    unsigned long   time_to_sleep;
    unsigned long   meals;
    unsigned long   conter;
    bool            flag_dead;
    bool            full;
    
    t_fork *fork;
    t_time *time;
} t_philo;







int *ft_philo(int n);

long to_int(char *str);
int ft_strcmp(char *s, char *s1);
char *ft_strdup(char *s1);

int check(int ac, char **av);
void out_exe(t_philo *philo);

#endif