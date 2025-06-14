#include "philo.h"
#include <stdio.h>

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        t_data data;
        validate_input(av, &data);
        initialize(&data);
        simulation(&data);

    }
    else
        error("ERROR! INVALID NUM OF ARGUMENTS");
}