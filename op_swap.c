#include "push_swap.h"

static void  swap(t_list **stack)
{
    t_list *res;

    if (!(*stack) || !((*stack)->next))
        return;
    res = *stack;
    *stack = (*stack)->next;
    (*stack)->next = res;
}

void sa(t_list **s_a)
{
    swap(s_a);
    write(1, "sa\n", 3);
}

void sb(t_list **s_b)
{
    swap(s_b);
    write(1, "sb\n", 3);
}

void ss(t_list **s_a, t_list **s_b)
{
    swap(s_a);
    swap(s_b);
    write(1, "ss\n", 3);
}