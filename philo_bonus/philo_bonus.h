/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:40:21 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/22 15:19:00 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define MAXINT 2147483647
# define MININT -2147483648
# define MICROSECONDS 1000
# define MILSECOND 60
# define ERRO_NUM "OPS! you have  invalid argument [enter just number]\n"
# define ERRO_NNUM "OPS! you have  invalid argument [the number can not be negative]\n"
# define ERRO_VNUM "OPS! you have  invalid argument [enter just valid number]\n"
# define ERRO_DNUM "OPS! you have  invalid argument [enter just digit]\n"
# define ERRO_INVARG "OPS! you have  invalid argument \n"
# define ERRO_INVARGEMTY "OPS! you have  invalid argument [ the string is emty]\n"
# define ERRO_INVARG_NOT_INT "OPS! you have  invalid argument [you must have enter agument not geart max or less min integer]\n"
# define MALLOC_FAILURE "Error: malloc failed to allocate memory\n"
# define TIME_FAILURE "Error: gettimeofday failed"

# define SEM_FORKS "/philo_forks"
# define SEM_PRINT "/philo_print"
# define SEM_MEALS "/philo_meals"
# define SEM_DEATH "/philo_death"
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

typedef struct timeval	t_time;

typedef struct s_data
{
    int             nbr_philo;
    int             time_eat;
    int             time_die;
    int             time_sleep;
    int             meals;
    bool            start_flag;
    int             ready_count;
    int             full_philos;
    long            start_similation;
    long long       start_time;
    bool            is_finish;
    sem_t           *sem_forks;
    sem_t           *sem_print;
    sem_t           *sem_meals;
    sem_t           *sem_death;
    bool            end_similation;
} t_data;

typedef struct s_philo
{
    int             id;
    int             meals_eaten;
    long long       last_meal_time;
    pid_t           pid;
    t_data          *data;
} t_philo;

void ft_putstr_fd(char *s, int fd);
long to_int(char *str);
int ft_strlen(char *s);
bool ft_check_data(int ac, char **av, t_data *arg);
bool ft_parc_digit(t_data *arg, char **av, int ac);
void *ft_malloc(size_t size, bool is_free, int ml_failure, char *s);
bool ft_init_data(t_data *arg, t_philo *philo);
long	gettime(void);
void ft_clean(t_data *data, int flag);
void ft_lifesycle(t_philo *philo);
void	ft_write(t_philo *philo, int flag);
bool	is_dead(t_philo *philo);
void ft_eat(t_philo *philo);
void ft_sleep(long mls, t_philo *philo);

#endif