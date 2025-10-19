/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:47 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 18:30:52 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeating_numbers(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = i + 1;
		while (res[j])
		{
			if (ft_atoi(res[i]) == ft_atoi(res[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	for_exit(t_list *a)
{
	write(2, "Error\n", 6);
	ft_lstclear(&a);
	exit(1);
}

int	cost_for_b(t_list *chosen, t_list **a, t_list **b, int size_a, int size_b)
{
	int idx_a = find_idx(a, biggest_min(a, chosen->index));
	int idx_b = find_pos(b, chosen->index);
	int ra_c = idx_a;
	int rra_c = size_a - idx_a;
	int rb_c = idx_b;
	int rrb_c = size_b - idx_b;
	int cost1;
	int cost2;
	int cost3;
	int cost4;
	int res1;
	int res2;

	cost1 = (ra_c > rb_c) ? ra_c : rb_c;
	cost2 = (rra_c > rrb_c) ? rra_c : rrb_c;
	cost3 = ra_c + rrb_c;
	cost4 = rb_c + rra_c;
	res1 = (cost1 > cost2) ? cost2 : cost1;
	res2 = (cost3 > cost4) ? cost4 : cost3;
	if (res1 < res2)
		return (res1);
	else 
		return (res2);
}

int	find_pos(t_list **a, int idx)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->index == idx)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
