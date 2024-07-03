/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/07/03 21:19:11 by mochenna         ###   ########.fr       */
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


#define RESET_COLOR   "\033[0m"
#define BLACK_TEXT    "\033[0;30m"
#define RED_TEXT      "\033[0;31m"
#define GREEN_TEXT    "\033[0;32m"
#define YELLOW_TEXT   "\033[0;33m"
#define BLUE_TEXT     "\033[0;34m"
#define MAGENTA_TEXT  "\033[0;35m"
#define CYAN_TEXT     "\033[0;36m"
#define WHITE_TEXT    "\033[0;37m"

typedef struct s_f
{
    pthread_mutex_t fork_mutex;
    int             fork_right;
    int             fork_left;
} t_fork;

struct s_ph
{
    pthread_t num_id;
    int     id;
    bool isrun;
    bool isdead;
    bool issleep;
    bool isthink;
    t_fork fork;
};

typedef struct s_time
{
    struct timeval time;
    unsigned long current;
    unsigned long eat;
    unsigned long dead;
    unsigned long sleep;
    unsigned long think;
}t_time;

typedef struct s_phi
{
    int   allphilo;
    int   Philosopher;
    int   time_to_eat;
    int   time_to_dead;
    int   time_to_sleep;
    int   time_to_think;
    int   meals;
    int   conter;
    bool            flag_dead;
    bool            full;
    bool            all_thread_run;
    t_time time;
    struct s_ph *philo;
} t_philo;

int *ft_philo(int n);
long to_int(char *str);
int check(int ac, char **av);
void convert_to_microseconds(t_philo *philo);
int init_philosopher(t_philo *philo);
#endif