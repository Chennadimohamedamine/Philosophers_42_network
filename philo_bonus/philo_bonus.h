/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:45:31 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/13 16:46:48 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PHILO_BONUS_H
#define PHILO_BONUS_H

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


#endif