#include "philo.h"


void philos_initalize(t_data *data)
{
    int i;
    i = 0;
    while(i < data->num_of_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].full = 0;
        data->philos[i].meals_count = 0;
		data->philos[i].data = data;

		if((data->philos[i].id % 2) != 0)
		{
			data->philos[i].left_fork = &data->forks[i + 1];
			data->philos[i].right_fork = &data->forks[i];
		}
		else
		{
			data->philos[i].right_fork = &data->forks[i];
			data->philos[i].left_fork = &data->forks[i + 1];
		}
		i++;
	}

}

void	initialize(t_data *data)
{
	int i;
	i = 0;
	data->philos = malloc(sizeof(t_philos) * data->num_of_philos);
	if(!data->philos)
		error("ERROR! ALLOCATION FAILED");
	data->forks = malloc(sizeof(t_fork) * data->num_of_philos);
	if (!data->forks)
		error("ERROR! ALLOCATION FAILED");
	if(pthread_mutex_init(&data->write_mutex, NULL))
			error("ERROR! FAILED TO INITIALIZE MUTEX");
	while(i < data->num_of_philos)
	{
        data->forks[i].fork_id = i;
		if(pthread_mutex_init(&data->forks[i].fork, NULL))
			error("ERROR! FAILED TO INITIALIZE MUTEX");
		i++;
	}
	
    philos_initalize(data);
	
}