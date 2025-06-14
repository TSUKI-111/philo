#include "philo.h"

void    error(char *error)
{
    ft_printf("%s \n", error);
    exit(1);
}


long    get_time(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL))
        return -1;
    
    return((tv.tv_sec * 1000) + (tv.tv_usec / 10000));

}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i]&& s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return(s1[i] - s2[i]);
    
}

void    write_f(char *str, t_philos *philo)
{
    long tiime;

    tiime = get_time() - philo->data->start_of_simulation;

    pthread_mutex_lock(&philo->data->write_mutex);
    if(!ft_strcmp(str, "sleep") && philo->data->end_of_simulation)
        ft_printf("%ld    %d  is  sleeping", tiime, philo->id);
    else if(!ft_strcmp(str, "eat") && philo->data->end_of_simulation)
        ft_printf("%ld    %d  is  eating", tiime, philo->id);
    else if(!ft_strcmp(str, "think") && philo->data->end_of_simulation)
        ft_printf("%ld    %d  is  is thinking", tiime, philo->id);
    else if(!ft_strcmp(str, "dead") && philo->data->end_of_simulation)
        ft_printf("%ld    %d  is  dead", tiime, philo->id);


    pthread_mutex_unlock(&philo->data->write_mutex);

}