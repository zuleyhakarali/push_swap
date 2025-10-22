/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:16 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 15:57:32 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stk1, t_stack **stk2)
{
	t_stack	*res;

	if (!(*stk2))
		return ;
	res = *stk2;
	*stk2 = (*stk2)->next;
	lstadd_front(stk1, res);
}

void	pa(t_stack **p_a, t_stack **stack_b)
{
	push(p_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **p_b, t_stack **stack_a)
{
	push(p_b, stack_a);
	write(1, "pb\n", 3);
}
