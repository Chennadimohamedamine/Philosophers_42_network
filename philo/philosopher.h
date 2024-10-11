/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/11 18:42:58 by mochenna         ###   ########.fr       */
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
#define MALLOC_FAILURE "Error: malloc failed to allocate memory\n"
#define TIME_FAILURE "Error: gettimeofday failed"
#define INIT 1
#define LOCK 2
#define UNLOCK 3
#define DESTORTY 4
#define CREATE 1
#define JOIN 2
#define DETACH 3
#define FORK 1
#define EAT 2
#define SLEEP 3
#define THINK 4

typedef pthread_mutex_t t_mtx;
typedef pthread_t t_ptd;
typedef struct s_data t_data;
typedef struct timeval t_time;

typedef struct s_share
{
    t_ptd  monitor;
    int    nbr_philo;
    int  time_eat;
    int  time_dead;
    int  time_sleep;
    int  meals;
} t_share;

typedef struct s_philo
{
    t_ptd       id_thread;
    int         id;
    long        meals_counter;
    long        last_meals_time;
    bool        is_dead;
    long long        start;
    t_mtx       *left_fork;
    t_mtx       *right_fork;
    t_data      *data;
    t_share     *arg;
} t_philo;

typedef struct s_data
{
    bool        start_flag;
    int         ready_count;
	long		start_similation;
    t_mtx       monitor;
	t_mtx       print;
	t_mtx       meals;
    t_mtx       mtx[4];
    long long   start_time;
	bool		end_similation;
} t_data;

// function utils
void	ft_putstr_fd(char *s, int fd);
long    to_int(char *str);
bool    ft_check_data(int ac, char **av, t_share *arg);
bool    ft_parc_digit(t_share *arg, char **av, int ac);

// sfae function 
int ft_mutex(t_mtx *mutex, int flag);
int ft_thread(pthread_t *thead, void *(*fun)(void *) , void *arg, int flag);
void *ft_malloc(size_t size, bool is_free, int ml_failure, char *s);
void ft_sleep(long mls);
// function excute
long gettime(void);
void ft_init_mutexs(t_data *data, t_share *arg, t_mtx *forks);
void endsimilation(t_philo *philo);
bool if_eat_all_meals(t_philo *philo);
bool if_dead(t_philo *philo);
void ft_write(t_philo *philo, int flag);
void ft_hold_forks(t_philo *philo);
#endif