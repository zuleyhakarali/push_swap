#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int main(int ac, char **av);
int repeating_numbers(char **res);
void sa(t_list **s_a);
void sb(t_list **s_b);
void ss(t_list **s_a, t_list **s_b);
void pa(t_list **p_a, t_list **stack_b);
void pb(t_list **p_b, t_list **stack_a);
void ra(t_list **r_a);
void rb(t_list **r_b);
void rr(t_list **r_a, t_list **t_b);
void rra(t_list **rr_a);
void rrb(t_list **rr_b);
void rrr(t_list **rr_a, t_list **rr_b);
void sorting(t_list **a, t_list **b);
void for_three(t_list **a);
void for_four(t_list **a, t_list **b);
void for_five(t_list **a, t_list **b);
void big_sort(t_list **a, t_list **b);

# endif