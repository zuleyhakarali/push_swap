#include "push_swap.h"

static void free_s(char **res)
{
    int i;

    i = 0;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

static char **args(int ac, char **av) // 27 satır, düzelt
{
    char **res;
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] == ' ')
            {
                res = ft_split(av[1], ' ');
                break;
            }
            i++;
        }
        if (!av[1][i])
            res = &av[1];
    }
    else
        res = &av[1];
    if (!repeating_numbers(res))
    {
        if (ac == 2 && ft_strchr(av[1], ' '))
            free_s(res);
        return (NULL);
    }
    return (res);
}

static int is_accaptable(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (!str[i])
        return (1);
    return (0);
}

static t_list *making_stack(char **res)
{
    long val;
    t_list *a;
    t_list *node;

    a = NULL;
    while (*res)
    {
        if (!is_accaptable(*res))
        {
            write(2, "Error\n", 6);
            return (NULL);
        }
        val = ft_atoi(*res);
        if (val > 2147483647 || val < -2147483648)
        {
            write(2, "Error\n", 6);
            return (NULL);
        }
        node = ft_lstnew(val);
        if (!node)
            return (NULL);
        ft_lstadd_back(&a, node);
        res++;
    }
    return (a);
}

int main(int ac, char **av)
{
    t_list *a;
    t_list *b;
    char **res;

    b = NULL;
    if (ac == 1)
        return (0);
    res = args(ac, av);
    if (!res || !*res)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    a = making_stack(res);
    if (!a)
    {
        if (ac == 2 && ft_strchr(av[1], ' '))
            free_s(res);
        return (1);
    }
    if (ac == 2 && ft_strchr(av[1], ' '))
        free_s(res);
    sorting(&a, &b);
    
    return (0);
}