#include "philo.h"

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        t_data data;
        validate_input(av, &data);
        initalize(&data);
    }
    else
        error("ERROR! INVALID NUM OF ARGUMENTS");
}