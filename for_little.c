/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_little.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:14:57 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 16:41:17 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack **a, int num)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (num == tmp->index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	min(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 2147483647;
	while (tmp)
	{
		if (i > tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

static void	find_and_replace(t_stack **a, t_stack **b)
{
	int	size_a;
	int	num;
	int	pos;
	int	res;

	num = min(a);
	size_a = lstsize(*a);
	pos = find_pos(a, num);
	if (pos == 0)
	{
		pb(b, a);
		return ;
	}
	else if (pos > size_a / 2)
	{
		res = size_a - pos;
		while (res-- > 0)
			rra(a);
	}
	else
		while (pos-- > 0)
			ra(a);
	pb(b, a);
}

void	for_little_nums(t_stack **a, t_stack **b, int size_a)
{
	int	push;

	push = size_a - 3;
	while (push-- > 0)
		find_and_replace(a, b);
	for_three(a);
	while (lstsize(*b) > 0)
		pa(a, b);
}
