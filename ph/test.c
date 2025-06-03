#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mut;
void    *mamak(void *aaa)
{
    pthread_mutex_lock(&mut);
    printf("waaaaaaaaaaaaaaaaaa\n");
    sleep(2);
    printf("lakaka");
    pthread_mutex_unlock(&mut);

    return(NULL);
}
int main()
{
    pthread_t lakaka, haahah;
    pthread_mutex_init(&mut, NULL);
    pthread_create(&lakaka, NULL,mamak, NULL);
    pthread_create(&haahah, NULL,mamak, NULL);
    pthread_join(lakaka,NULL);
    pthread_join(haahah,NULL);
    pthread_mutex_destroy(&mut);



}