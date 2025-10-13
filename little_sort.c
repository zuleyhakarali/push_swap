#include "push_swap.h"

void for_three(t_list **a)
{
    int fir;
    int sec;
    int thi;

    fir = (*a)->content;
    sec = (*a)->next->content;
    thi = (*a)->next->next->content;
    if (fir > sec && sec > thi)
    {
        sa(a);
        rra(a);
    }
    if (fir > thi && thi > sec)
        ra(a);
    if (sec > fir && fir > thi)
        rra(a);
    if (thi > fir && fir > sec)
        sa(a);
    if (sec > thi && thi > fir)
    {
        sa(a);
        ra(a);
    }
}

void for_four(t_list **a, t_list **b)
{
    int min;
    int i;
    int idx;
    t_list *tmp;

    i = 0;
    idx = 0;
    tmp = *a;
    min = (*a)->content;
    while (tmp)
    {
        if (min > tmp->content)
        {
            min = tmp->content;
            idx = i;
        }
        tmp = tmp->next;
        i++;
    }
    while (idx-- > 0)
        ra(a);
    pb(b, a);
    for_three(a);
    pa(a, b);
}

void for_five(t_list **a, t_list **b)
{
    int min;
    int i;
    int idx;
    t_list *tmp;

    i = 0;
    idx = 0;
    tmp = *a;
    min = (*a)->content;
    while (tmp)
    {
        if (min > tmp->content)
        {
            min = tmp->content;
            idx = i;
        }
        tmp = tmp->next;
        i++;
    }
    while (idx-- > 0)
        ra(a);
    pb(b, a);
    for_four(a, b);
    pa(a, b);
}

void sorting(t_list **a, t_list **b)
{
    int i;

    i = ft_lstsize(a);
    if (i == 2)
    {
        if ((*a)->content > (*a)->next->content)
            sa(a);
    }
    if (i == 3)
        for_three(a);
    if (i == 4)
        for_four(a, b);
    if (i == 5)
        for_five(a, b);
    else
        big_sort(a, b);
}