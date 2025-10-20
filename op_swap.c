/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:37 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 12:58:13 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*fir;
	t_list *sec;

	if (!(*stack) || !((*stack)->next))
		return ;
	fir = *stack;
	sec = (*stack)->next;
	fir->next = sec->next;
	sec->next = fir;
	*stack = sec;
}

void	sa(t_list **s_a)
{
	swap(s_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **s_b)
{
	swap(s_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
	write(1, "ss\n", 3);
}
