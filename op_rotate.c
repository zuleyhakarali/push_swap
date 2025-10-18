/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:32 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 17:03:42 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*res;
	t_list	*tmp;

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

void	ra(t_list **r_a)
{
	rotate(r_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **r_b)
{
	rotate(r_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **r_a, t_list **r_b)
{
	rotate(r_a);
	rotate(r_b);
	write(1, "rr\n", 3);
}
