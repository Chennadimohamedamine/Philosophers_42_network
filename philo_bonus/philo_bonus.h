/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:38:29 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/15 16:46:32 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <semaphore.h>

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

typedef struct s_share
{
    int    nbr_philo;
    int  time_eat;
    int  time_dead;
    int  time_sleep;
    int  meals;
} t_share;

typedef struct s_data
{
    bool        start_flag;
    int         ready_count;
    int         full_philos;
	long		start_similation;
    long long   start_time;
	bool		end_similation;
} t_data;

typedef struct s_philo
{
    int         id;
    long        meals_counter;
    long        last_meals_time;
    bool        is_dead;
    long long        start;
    t_data      *data;
    t_share     *arg;
} t_philo;
void	ft_putstr_fd(char *s, int fd);
long    to_int(char *str);
int ft_strlen(char *s);
bool    ft_check_data(int ac, char **av, t_share *arg);
bool    ft_parc_digit(t_share *arg, char **av, int ac);
#endif