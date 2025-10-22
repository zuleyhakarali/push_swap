/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:32 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 15:58:39 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*res;
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	res = *stack;
	*stack = (*stack)->next;
	res->next = NULL;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = res;
}

void	ra(t_stack **r_a)
{
	rotate(r_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **r_b)
{
	rotate(r_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **r_a, t_stack **r_b)
{
	rotate(r_a);
	rotate(r_b);
	write(1, "rr\n", 3);
}
