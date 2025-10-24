/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:16 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/24 19:08:34 by zkarali          ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **stack_b)
{
	push(a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **stack_a)
{
	push(b, stack_a);
	write(1, "pb\n", 3);
}

void is_acceptable_for_int(char **s)
{
	long val;
	int i;

	i = 0;
	while(*s)
	{
		val = ft_atoi(*s);
		if (val > 2147483647 || val < -2147483648)
		{
			i++;
			break;
		}
		s++;
	}
	if (i == 1)
		free_s(s);
}