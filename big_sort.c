/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:10:31 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/24 15:44:44 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_max_bit(t_stack **a)
{
	int		max_idx;
	int		max_bit;
	t_stack	*tmp;

	max_idx = -2147483648;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index > max_idx)
			max_idx = tmp->index;
		tmp = tmp->next;
	}
	max_bit = 0;
	while ((max_idx >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	big_sort(t_stack **a, t_stack **b, int size_a)
{
	int	max_bit;
	int	i;
	int	s_a;

	max_bit = calculate_max_bit(a);
	i = 0;
	while (i < max_bit)
	{
		s_a = size_a;
		while (s_a > 0)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(b, a);
			s_a--;
		}
		while (lstsize(*b) > 0)
			pa(a, b);
		i++;
	}
}
