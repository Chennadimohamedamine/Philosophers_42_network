/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:06:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/09/29 18:04:32 by mochenna         ###   ########.fr       */
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