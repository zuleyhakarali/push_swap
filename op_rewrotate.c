#include "push_swap.h"

static void rewrotate(t_list **stack)
{
    t_list *res;
    t_list *list;

    if (!(*stack) || !(*stack)->next)
        return;
    list = *stack;
    while (list->next->next != NULL)
        list = list->next;
    res = list->next;
    list->next = NULL;
    res->next = *stack;
    *stack = res;
}

void rra(t_list **rr_a)
{
    rewrotate(rr_a);
    write(1, "rra\n", 4);
}

void rrb(t_list **rr_b)
{
    rewrotate(rr_b);
    write(1, "rrb\n", 4);
}

void rrr(t_list **rr_a, t_list **rr_b)
{
    rewrotate(rr_a);
    rewrotate(rr_b);
    write(1, "rrr\n", 4);
}