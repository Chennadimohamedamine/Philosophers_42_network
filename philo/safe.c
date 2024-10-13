/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:06:28 by mochenna          #+#    #+#             */
/*   Updated: 2024/10/13 17:16:04 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *ft_malloc(size_t size, bool is_free, int ml_failure, char *s)
{
    static void *safe_allocation[1000];
    static int index;
    void *allocat;
    int i;

    if (is_free)
    {
        i = 0;
        while (safe_allocation[i])
            free(safe_allocation[i++]);
        index = 0;
        safe_allocation[index] = NULL;
        if (ml_failure == -1337)
            ft_putstr_fd(s, 2);
        return (NULL);
    }
    allocat = malloc(size);
    if (!allocat)
        return (ft_malloc(0, true, -1337, MALLOC_FAILURE));
    safe_allocation[index++] = allocat;
    safe_allocation[index] = NULL;
    return (allocat);
}

int ft_mutex(t_mtx *mutex, int flag)
{
    if (flag == INIT)
        return (pthread_mutex_init(mutex, NULL));
    else if (flag == LOCK)
        return (pthread_mutex_lock(mutex));
    else if (flag == UNLOCK)
        return (pthread_mutex_unlock(mutex));
    else if (flag == DESTORTY)
        return (pthread_mutex_destroy(mutex));
    return (1337);
}
int ft_thread(pthread_t *thead, void *(*fun)(void *), void *arg, int flag)
{
    if (flag == CREATE)
        return (pthread_create(thead, NULL, fun, arg));
    else if (flag == JOIN)
        return (pthread_join(*thead, NULL));
    else if (flag == DETACH)
        return (pthread_detach(*thead));
    return (1337);
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
bool ft_check_data(int ac, char **av, t_share *arg)
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
    if (ft_parc_digit(arg, av, ac))
        return (true);
    return (false);
}