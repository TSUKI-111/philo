#include "philo.h"
void    eat(t_philos *philo)
{
    pthread_mutex_lock(&philo->right_fork->fork);
    pthread_mutex_lock(&philo->left_fork->fork);

    if(philo->data->num_of_meals > 0  && philo->meals_count == philo->data->num_of_meals)
    {
        philo->full = 1;
        return;
    }
    write_f("eat", philo);
    usleep(philo->data->time_to_eat * 1000);
    philo->meals_count++;
    pthread_mutex_unlock(&philo->right_fork->fork);
    pthread_mutex_unlock(&philo->left_fork->fork);
}



void    *routine(void *data)
{

    t_philos *philo;
    philo = (t_philos *) data;
    
    while (!philo->data->end_of_simulation)
    {
        if(philo->full)
        break;
        eat(philo);
        
        write_f("sleep", philo);
        usleep(philo->data->time_to_sleep * 1000);
        
        
        
    }
    


    return(NULL);
}

void simulation(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_of_philos)
    {
        if(pthread_create(&data->philos[i].philo_thread,NULL,routine, &data->philos[i]))
            return;
        i++;
    }
    
    data->start_of_simulation = get_time();
    i = 0;
    while (i <data->num_of_philos)
    {
        if(pthread_join(data->philos[i].philo_thread, NULL))
            return;
        i++;
    }
    



}