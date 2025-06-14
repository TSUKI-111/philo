#include "philo.h"
static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

static void    check_maxint(t_data *data)
{
    if(data->num_of_meals >= 2147483647 || data->num_of_philos >= 2147483647 || data->time_to_die >= 2147483647 || data->time_to_eat >= 2147483647 || data->time_to_sleep >= 2147483647)
        error("ERROR! MAX INT"); 
}
static long	ft_atoi(char *str)
{
	long	result;
	int	i;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			error("ERROR! NEGATIVE VALUE!!");
		i++;
	}
	while (str[i])
	{
		if(ft_isalpha(str[i]))
			error("ERROR!");
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
 void	validate_input(char **av, t_data *data)
 {
    data->num_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
	data->end_of_simulation = 0;
    if(av[5])
        data->num_of_meals = ft_atoi(av[5]);
    check_maxint(data);
 }
