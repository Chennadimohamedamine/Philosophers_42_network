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

philo->Philosoph.id = (pthread_t *)malloc(philo->allphilo * sizeof(pthread_t) + 1);
    philo->Philosoph.handling_error = NULL;
    if (pthread_create(&create_id,NULL,shadow_clone,philo) != 0)
        return (printf(" ==>  Error: pthread_create() failed\n"), 1);
    if (pthread_join(create_id,(void **) &philo->Philosoph.handling_error))
        return (printf(" ==>  Error: pthread_join() failed\n"), 1);
    if (ft_strcmp(philo->Philosoph.handling_error,"successful") == 0)
        printf("create threads is %s \n",philo->Philosoph.handling_error);
    else
        return (out_exe(philo), printf("thread create error: [ type %s ]\n",philo->Philosoph.handling_error), 1);

// int l = 1;
// void *create_thread(void *k) {
//     l++;
//     return k;
// }
// void *philo_thread(void *p) {
//     long i = 0;
//     while (i < 100000000)
//     {
//         sleep(1000);
//         l++;
//         i++;
//     }
//     return p;
// }
// void *shadow_clone(void *p) {
//     long i;
//     t_philo *philo = (t_philo *)p;
//     if (philo == NULL) {
//         printf("Error: philo is NULL in shadow_clone\n");
//         return (void *)1;
//     }
//     pthread_t *th = (pthread_t *)malloc(philo->allphilo * sizeof(pthread_t));
//     i = 1;
//     if (th == NULL) {
//         return (printf(" ==> Error: malloc() failed\n"), (void *)1);
//     }
//     while (i <= philo->allphilo)
//     {
//         if (pthread_create(&th[i], NULL, philo_thread, (void *)philo) != 0) {
//             free(th);
//             return (printf(" ==> Error: pthread_create() failed\n"), (void *)1);
//         }
//         // printf("the thread [ %ld ] is create \n",i);
//        if (pthread_join(th[i], NULL)) {
//             free(th);
//             return (printf(" ==> Error: pthread_join() failed\n"), (void *)1);
//         }
//         // printf("the thread [ %ld ] is finish exuction\n",i);
//         i++;
//     }
//     free(th);
//     printf("============= ============== ===============\n\n");
//     printf("the value %d\n",l);
//     return NULL;
// }
// int execute_program(t_philo *philo)
// {
//     pthread_t man_thread;
    
//     if (pthread_create(&man_thread,NULL,shadow_clone,philo) != 0)
//         return (printf(" ==>  Error: pthread_create() failed\n"), 1);
//     if (pthread_join(man_thread,NULL))
//             return (printf(" ==>  Error: pthread_join() failed\n"), 1);
//     return (0);
// }