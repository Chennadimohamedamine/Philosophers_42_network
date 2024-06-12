/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/06/12 15:48:28 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_C
#define PHILOSOPHER_C

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>


#define MAXINT 2147483647 
#define MININT -2147483648

struct philosopher
{
    pthread_t       id;
    unsigned long   fork[2];
    unsigned long   eat;
    unsigned long   think;
    unsigned long   sleep;
    unsigned long   meals;
    char            full;
};


typedef struct s_ph
{
    unsigned long allphilo;
    unsigned long Philosopher;
    unsigned long time_to_eat;
    unsigned long time_to_dead;
    unsigned long time_to_sleep;
    unsigned long meals;
    unsigned long fork;
    struct timeval time;
    pthread_mutex_t mutex;
    struct philosopher Philosoph;
} t_philo;

int *ft_philo(int n);


void ft_print_(int number,char *s);
void print_int(int n);
void printstr(char *s);

long	to_int(char *str);

void ft_perror(char *s);
void check(int ac, char **av);
void failure_thread(int i,char *s);


#endif