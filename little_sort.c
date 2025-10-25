/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:50:13 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/25 15:11:46 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_three(t_stack **a)
{
	long	fir;
	long	sec;
	long	thi;

	fir = (*a)->content;
	sec = (*a)->next->content;
	thi = (*a)->next->next->content;
	if (fir > sec && sec > thi)
	{
		sa(a);
		rra(a);
	}
	else if (fir > thi && thi > sec)
		ra(a);
	else if (sec > fir && fir > thi)
		rra(a);
	else if (thi > fir && fir > sec)
		sa(a);
	else if (sec > thi && thi > fir)
	{
		sa(a);
		ra(a);
	}
}

static int	find_min_idx(t_stack **a)
{
	int		i;
	int		idx;
	long	min;
	t_stack	*tmp;

	i = 0;
	idx = 0;
	min = (*a)->content;
	tmp = *a;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (idx);
}

static void	for_four(t_stack **a, t_stack **b, int i)
{
	int	min;
	int	res;

	min = find_min_idx(a);
	if (min <= i / 2)
	{
		while (min-- > 0)
			ra(a);
	}
	else
	{
		res = i - min;
		while (res-- > 0)
			rra(a);
	}
	pb(b, a);
	for_three(a);
	pa(a, b);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	i;

	i = lstsize(*a);
	indexing(a, i);
	if (is_sorted(a))
		return ;
	else if (i == 1)
		return ;
	else if (i == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		return ;
	}
	else if (i == 3)
		for_three(a);
	else if (i == 4)
		for_four(a, b, i);
	else if (i < 25)
		for_little_nums(a, b, i);
	else
		big_sort(a, b, i);
}
