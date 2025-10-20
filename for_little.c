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

    num = min(b);
    size_a = ft_lstsize(*a);
    pos = find_pos(a, num);
    if (pos == 0)
    {
        pb(b, a);
        return ;
    }
    else if (pos > size_a / 2)
        while (size_a - pos-- > 0)
            rra(a);
    else 
        while (pos-- > 0)
            ra(a);
    pb(b, a);
}

static int max(t_list **b)
{
    int i;
    t_list *tmp;

    tmp = *b;
    i = -2147483648;
    while (tmp)
    {
        if (i < tmp->index)
            i = tmp->index;
        tmp = tmp->next;
    }
    return (i);
}

static void back(t_list **a, t_list **b)
{
    int max_idx;
    int pos;
    int size_b;

    while (*b)
    {
        max_idx = max(b);
        size_b = ft_lstsize(*b);
        pos = find_pos(b, max_idx);
        if (pos == 0)
            pa(a, b);
        else if (pos > size_b / 2)
            while (size_b - pos-- > 0)
                rrb(b);
        else 
            while (pos-- > 0)
                rb(b);
    }
}

static void is_a_sorted(t_list **a)
{
    int min_idx;
    int rep;
    int size_a;
    int pos;

    size_a = ft_lstsize(*a);
    min_idx = min(a);
    pos = find_pos(a, min_idx);
    if (pos > size_a / 2)
    {
        rep = size_a - pos;
        while (rep-- > 0)
            rra(a);
    }
    else 
        while (pos-- > 0)
            ra(a);
}

void for_little(t_list **a, t_list **b)
{
    int push;

    indexing(a);
    push = ft_lstsize(*a) - 3;
    while (push-- > 0)
        find_and_replace(a, b);
    for_three(a);
    back(a, b);
    is_a_sorted(a);
}