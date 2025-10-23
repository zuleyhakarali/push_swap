#include "push_swap.h"

static int find_pos(t_list **a, int num)
{
    int i;
    t_list *tmp;
    
    tmp = *a;
    i = 0;
    while (tmp)
    {
        if (num == tmp->index)
        return (i);
        tmp = tmp->next;
        i++;
    }
    return (0);
}

static int min(t_list **a)
{
    int i;
    t_list *tmp;

    tmp = *a;
    i = 2147483647;
    while (tmp)
    {
        if (i > tmp->index)
            i = tmp->index;
        tmp = tmp->next;
    }
    return (i);
}

static void find_and_replace(t_list **a, t_list **b)
{
    int size_a;
    int num;
    int pos;
    int res;

    num = min(a);
    size_a = ft_lstsize(*a);
    pos = find_pos(a, num);
    if (pos == 0)
    {
        pb(b, a);
        return ;
    }
    else if (pos > size_a / 2)
    {
        res = size_a - pos;
        while (res-- > 0)
            rra(a);
    }
    else 
        while (pos-- > 0)
            ra(a);
    pb(b, a);
}

void for_little_nums(t_list **a, t_list **b, int size_a)
{
    int push;

    indexing(a, size_a);
    push = size_a - 3;
    while (push-- > 0)
        find_and_replace(a, b);
    for_three(a);
    while (ft_lstsize(*b) > 0)
        pa(a, b);
}
