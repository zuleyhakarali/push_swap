/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:42 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/24 14:46:00 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			content;
	long			index;
	struct s_stack	*next;
}					t_stack;

void	sa(t_stack **s_a);
void	sb(t_stack **s_b);
void	ss(t_stack **s_a, t_stack **s_b);
void	pa(t_stack **p_a, t_stack **stack_b);
void	pb(t_stack **p_b, t_stack **stack_a);
void	ra(t_stack **r_a);
void	rb(t_stack **r_b);
void	rr(t_stack **r_a, t_stack **t_b);
void	rra(t_stack **rr_a);
void	rrb(t_stack **rr_b);
void	rrr(t_stack **rr_a, t_stack **rr_b);

int		main(int ac, char **av);
int		is_only_space(char *s);
int		is_acceptable_str(char *str);
void	free_s(char **res);
void	for_exit(t_stack *a);

void	sorting(t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
void	for_three(t_stack **a);
void	for_little_nums(t_stack **a, t_stack **b, int size_a);

void	indexing(t_stack **stack, int size);
void	big_sort(t_stack **a, t_stack **b, int size_a);

int		lstsize(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack	*lstnew(long content);

#endif
