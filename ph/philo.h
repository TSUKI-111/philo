#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf/ft_printf.h"
#include <sys/time.h>

struct s_data;
typedef struct s_fork
{
    int fork_id;
    pthread_mutex_t fork;
} t_fork;

typedef struct  s_philos
{
    int id;
    pthread_t philo_thread;
    int meals_count;
    int full;
    t_fork *right_fork;
    t_fork *left_fork;
    struct s_data *data; 

} t_philos;
typedef struct s_data
{
    long num_of_philos;
    long time_to_eat;
    long time_to_die;
    long time_to_sleep;
    long num_of_meals;
    long start_of_simulation;
    int end_of_simulation;
    pthread_mutex_t write_mutex;
    t_philos *philos;
    t_fork *forks;


}t_data;

 void   validate_input(char **av, t_data *data);
void    error(char *error);
void	initialize(t_data *data);
void lakaka(t_data *data);

long    get_time(void);
int ft_strcmp(char *s1, char *s2);
void    write_f(char *str, t_philos *philo);
void simulation(t_data *data);
void    *routine(void *data);
#endif