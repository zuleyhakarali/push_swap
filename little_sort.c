#include "push_swap.h"

void for_three(t_list **a)
{
    long fir;
    long sec;
    long thi;

    fir = (*a)->content;
    sec = (*a)->next->content;
    thi = (*a)->next->next->content;
    if (fir > sec && sec > thi) // 3 2 1
    {
        sa(a);
        rra(a);
    }
    else if (fir > thi && thi > sec) // 3 1 2
    ra(a);
    else if (sec > fir && fir > thi) // 2 3 1
        rra(a);
    else if (thi > fir && fir > sec) // 2 1 3
        sa(a);
    else if (sec > thi && thi > fir) //1 3 2
    {
        sa(a);
        ra(a);
    }
}

static int find_min_idx(t_list **a)
{
    int i;
    int idx;
    long min;
    t_list *tmp;

    i = 0;
    idx = 0;
    min = (*a)->content;
    tmp = *a;
    while (tmp != NULL)
    {
        if (min > tmp->content)
        {
            min = tmp->content;
            idx = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (idx);
}

static void for_four(t_list **a, t_list **b, int i)
{
    int idx;

    idx = find_min_idx(a);
    if (idx <= i / 2)
    {
        while (idx-- > 0)
            ra(a);
    }
    else
    {
        while (idx++ < i - 1)
            rra(a);
    }
    pb(b, a);
    for_three(a);
    pa(a, b);
}

static void for_five(t_list **a, t_list **b, int i)
{
    int idx;

    idx = find_min_idx(a);
    if (idx <= i / 2)
    {
        while (idx-- > 0)
            ra(a);
    }
    else
    {
        while (idx++ < i - 1)
            rra(a);
    }
    pb(b, a);
    for_four(a, b, i - 1);
    pa(a, b);
}

void sorting(t_list **a, t_list **b)
{
    int i;

    i = ft_lstsize(*a);
    if (i == 2)
    {
        if ((*a)->content > (*a)->next->content)
            sa(a);
    }
    else if (i == 3)
        for_three(a);
    else if (i == 4)
        for_four(a, b, i);
    else if (i == 5)
        for_five(a, b, i);
    else
        big_sort(a, b, i);
}