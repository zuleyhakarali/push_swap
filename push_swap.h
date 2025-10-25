/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:42 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/25 15:48:24 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			content;
	long			index;
	struct s_stack	*next;
}					t_stack;

void	sa(t_stack **a);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	pa(t_stack **a, t_stack **stack_b);
void	pb(t_stack **b, t_stack **stack_a);

int		main(int ac, char **av);
int		is_only_space(char *s);
int		is_acceptable_str(char *str);
int		is_acceptable_for_int(char **s);
void	free_s(char **res);
void	for_exit(t_stack *a);

void	indexing(t_stack **stack, int size);
void	sorting(t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
void	for_three(t_stack **a);
void	for_little_nums(t_stack **a, t_stack **b, int size_a);

void	big_sort(t_stack **a, t_stack **b, int size_a);

int		lstsize(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack	*lstnew(long content);

#endif
