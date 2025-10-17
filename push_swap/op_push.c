#include "push_swap.h"

static void push(t_list **stk1, t_list **stk2)
{
    t_list *res;

    if (!(*stk2))
        return;
    res = *stk2;
    *stk2 = (*stk2)->next;
    ft_lstadd_front(stk1, res);
}

void pa(t_list **p_a, t_list **stack_b)
{
    push(p_a, stack_b);
    write(1, "pa\n", 3);
}

void pb(t_list **p_b, t_list **stack_a)
{
    push(p_b, stack_a);
    write(1, "pb\n", 3);
}