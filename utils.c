#include "push_swap.h"

int repeating_numbers(char **res)
{
    int i;
    int j;

    i = 0;
    while (res[i])
    { 
        j = i + 1;
        while (res[j])
        {
            if (ft_atoi(res[i]) == ft_atoi(res[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

