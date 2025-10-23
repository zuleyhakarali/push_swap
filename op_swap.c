/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:37 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 16:02:19 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*fir;
	t_stack	*sec;

	if (!(*stack) || !((*stack)->next))
		return ;
	fir = *stack;
	sec = (*stack)->next;
	fir->next = sec->next;
	sec->next = fir;
	*stack = sec;
}

void	sa(t_stack **s_a)
{
	swap(s_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **s_b)
{
	swap(s_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **s_a, t_stack **s_b)
{
	swap(s_a);
	swap(s_b);
	write(1, "ss\n", 3);
}
