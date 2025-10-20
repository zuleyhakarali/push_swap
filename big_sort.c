#include "push_swap.h"

int maximum(t_list **a)
{
    int max_idx;
    int max_bit;
    t_list *tmp;

    max_idx = -2147483648;
    tmp = *a;
    while (tmp)
    {
        if (tmp->index > max_idx)
            max_idx = tmp->index;
        tmp = tmp->next;
    }
    max_bit = 0;
    while ((max_idx >> max_bit) != 0)
        max_bit++;
    return (max_bit);
}

void	big_sort(t_list **a, t_list **b)
{
    int     max_bit;
    int     i;
    int     size_a;

	indexing(a);
    max_bit = maximum(a);
    i = 0;
    while (i < max_bit)
    {
        size_a = ft_lstsize(*a);
        while (size_a > 0)
        {
            if ((((*a)->index >> i) & 1) == 1)
                ra(a);
            else
                pb(b, a);
            size_a--;
        }
        while (ft_lstsize(*b)> 0)
            pa(a, b);
        i++;
    }
}