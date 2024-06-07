#include <libc.h>
#include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include "philo/philosopher.h"

void *p_w(void *arg)
{
    int i = 1000;
    while(i >= 0)
    {
        printf("t ==> 1\n");
        i--;
        usleep(400);
    }
    return NULL;
}
void *p_h(void *arg)
{
    int i = 1000;
    while(i >= 0)
    {
        printf("t ==> 2\n");
        i--;
        usleep(400);
    }
    return NULL;
}
int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_mutex_t *mutex;
    t_pilo philo;
    if (pthread_create(&t2,NULL,&p_h,NULL) != 0)
        exit(1);
    if (pthread_create(&t1,NULL,&p_w,NULL) != 0)
        exit(1);
    if (pthread_join(t1,NULL) != 0)
        exit(1);
    if (pthread_join(t2,NULL) != 0)
        exit(1);
    
    return 0;
}