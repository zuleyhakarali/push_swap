#include "push_swap.h"

int biggest_min(t_list **b, int a_val)
{
    t_list *tmp;
    int min;

    min = -2147483647;
    tmp = (*b);
    while (tmp)
    {
        if (a_val > tmp->index)
        {
            if (min < tmp->index)
                min = tmp->index;
        }
        tmp = tmp->next;
    }
    if (min == -2147483647)
    {
        tmp = (*b);
        min = tmp->index;
        while (tmp)
        {
            if (tmp->index < min)
                min = tmp->index;
            tmp = tmp->next;
        }
    }
    return (min);
}

int find_idx(t_list **b, int big_min)
{
    t_list *tmp;
    int i;

    tmp = (*b);
    i = 0;
    while (tmp)
    {
        if (tmp->index == big_min)
            return i;
        tmp = tmp->next;
        i++;
    }
    return (-1);
}

int cost_for_b(t_list *node, t_list **a, t_list **b, int size_a, int size_b)
{
    int big_min;
    int idx_a;
    int idx_b;
    int val;

    val = node->index;
    big_min = biggest_min(b, val);
    idx_b = find_idx(b, big_min);
    if (idx_b == -1)
        idx_b = 0;
    idx_a = find_idx(a, val);
    if (idx_a > size_a / 2)
        idx_a = size_a - idx_a;
    if (idx_b > size_b / 2)
        idx_b = size_b - idx_b;
    return (idx_a + idx_b);
}

int find_pos(t_list **a, int idx)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = (*a);
    while (tmp)
    {
        if (tmp->index == idx)
            return (i);
        tmp = tmp->next;
        i++;
    }
    return (-1);
}

void placement(t_list **a, t_list **b, t_list *chosen, int size_a, int size_b)
{
    int big_m;
    int pos_a;
    int pos_b;

    pos_a = find_pos(a, chosen->index);
    big_m = biggest_min(b, chosen->index);
    pos_b = find_idx(b, big_m);
    if (pos_a < size_a / 2 && pos_b < size_b / 2)
        rr(a, b);
    else if (pos_a >= size_a / 2 && pos_b >= size_b / 2)
        rrr(a, b);
    else if (pos_a < size_a / 2 && pos_b >= size_b / 2)
    {
        ra(a);
        rrb(b);
    }
    else
    {
        rra(a);
        rb(b);
    }
}

void best_move(t_list **a, t_list **b, int size_a, int size_b)
{
    int cost1;
    int cost2;
    t_list *tmp;
    t_list *chosen;

    if (!a || !*a || !b)
        return;
    cost2 = 2147483647;
    tmp = (*a);
    while (tmp)
    {
        cost1 = cost_for_b(tmp, a, b, size_a, size_b);
        if (cost1 < cost2)
        {
            cost2 = cost1;
            chosen = tmp;
        }
        tmp = tmp->next;
    }
    if (!chosen)
        return;
    placement(a, b, chosen, size_a, size_b);
    pb(b, a);
}

void big_sort(t_list **a, t_list **b, int size_a)
{
    int size_b;
    t_list *tmp;

    size_b = 0;
    indexing(a);
    pb(b, a);
    pb(b, a);
    size_a -= 2;
    size_b += 2;
    while (size_a > 0)
    {
        best_move(a, b, size_a, size_b);
        size_a--;
        size_b++;
    }
    while (*b)
        pa(a, b);
    tmp = (*a);
    while (tmp->next != NULL)
        tmp = tmp->next;
    if ((*a)->index > tmp->index)
        rra(a);
}