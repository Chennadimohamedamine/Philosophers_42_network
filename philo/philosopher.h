/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/09/29 18:04:07 by mochenna         ###   ########.fr       */
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
#define MICROSECONDS 1000
#define MILSECOND 60
#define ERRO_NUM "OPS! you have  invalid argument [enter just number]\n"
#define ERRO_NNUM "OPS! you have  invalid argument [the number can not be negative]\n"
#define ERRO_VNUM "OPS! you have  invalid argument [enter just valid number]\n"
#define ERRO_DNUM "OPS! you have  invalid argument [enter just digit]\n"
#define ERRO_INVARG "OPS! you have  invalid argument \n"
#define ERRO_INVARGEMTY "OPS! you have  invalid argument [ the string is emty]\n"
#define ERRO_INVARG_NOT_INT "OPS! you have  invalid argument [you must have enter agument not geart max or less min integer]\n"
#define MALLOC_FAILURE "error: malloc failed to allocate memory\n"
#define INIT 1
#define LOCK 2
#define UNLOCK 3
#define DESTORTY 4
#define CREATE 1
#define JOIN 2
#define DETACH 3

typedef pthread_mutex_t t_mtx;
typedef struct s_data t_data;

typedef struct s_fork
{
    t_mtx   fork;
    int     fork_id;
} t_fork;

typedef struct s_philo
{
    pthread_t num_id;
    int     id;
    long    meals_counter;
    long    last_meals_counter;
    bool    is_dead;
    t_fork *fork_left;
    t_fork *fork_right;
    t_data *data;
} t_philo;

typedef struct s_time
{
    struct timeval time;
    unsigned long current;
    unsigned long eat;
    unsigned long dead;
    unsigned long sleep;
    unsigned long think;
}t_time;

struct s_data
{
    int   philosophers;
    int   time_to_eat;
    int   time_to_dead;
    int   time_to_sleep;
    int   time_to_think;
    int   meals;
    int   conter;
    bool  is_out;
    bool  malloc_failure;
    bool  all_thread_run;
    t_philo *philo;
    t_fork  *fork;
    t_time  time;
};






void	ft_putstr_fd(char *s, int fd);
long    to_int(char *str);
bool    checker(int ac, char **av);
int     ft_mutex(t_mtx *mutex, int flag);
int     ft_thread(pthread_t *thead, void *(*fun)(void *) , void *arg, int flag);
void    *ft_malloc(size_t size, t_data *data);

#endif