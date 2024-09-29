/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:06:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/09/29 18:31:32 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *ft_malloc(size_t size, t_data *data)
{
    void *allocat;
    
    allocat = malloc(size);
    if (!allocat)
    {
        data->malloc_failure = true;
        return (NULL);
    }
    return (allocat);
}

int ft_mutex(t_mtx *mutex, int flag)
{
    int status_error;

    if (flag == INIT)
        status_error = pthread_mutex_init(mutex, NULL);
    else if (flag == LOCK)
        status_error = pthread_mutex_lock(mutex);
    else if (flag == UNLOCK)
        status_error = pthread_mutex_unlock(mutex);
    else if (flag == DESTORTY)
        status_error = pthread_mutex_destroy(mutex);
    else
        status_error = -1337;
    return (status_error);
}
int ft_thread(pthread_t *thead, void *(*fun)(void *) , void *arg, int flag)
{
    int status_error;

    if (flag == CREATE)
        status_error = pthread_create(thead, NULL, fun, arg);
    else if (flag == JOIN)
        status_error = pthread_join(*thead, NULL);
    else if (flag == DETACH)
        status_error = pthread_detach(*thead);
    else
        status_error = -1337;
    return (status_error);
}

bool valid_input(char *s)
{
    int i;

    i = 0;
    while (s[i] == ' ')
        i++;
    if (!s[i])
        return (ft_putstr_fd(ERRO_NUM, 2), true);
    else if (s[i] == '-')
        return (ft_putstr_fd(ERRO_NNUM, 2), true);
    else if ((s[i] == '+' && (!s[i + 1] || !(s[i + 1] >= '0' && s[i + 1] <= '9'))))
        return (ft_putstr_fd(ERRO_VNUM, 2), true);
    else if (s[i] == '+')
        i++;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (ft_putstr_fd(ERRO_DNUM, 2), true);
        i++;
    }
    return (false);
}
bool checker(int ac, char **av)
{
    int i;
    long r;

    if (ac != 5 && ac != 6)
            return (ft_putstr_fd(ERRO_INVARG, 2), true);
    i = 1;
    while (i < ac)
    {
        if (!av[i][0])
            return (ft_putstr_fd(ERRO_INVARGEMTY, 2), true);
        if (valid_input(av[i]))
            return (1);
        r = to_int(av[i]);
        if (r < MININT || r > MAXINT)
            return (ft_putstr_fd(ERRO_INVARG_NOT_INT, 2), true);
        i++;
    }
    return (false);
}