/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:50:13 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 18:32:29 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_three(t_list **a)
{
	long	fir;
	long	sec;
	long	thi;

	fir = (*a)->content;
	sec = (*a)->next->content;
	thi = (*a)->next->next->content;
	
	if (thi > sec && sec > fir)
		return ;
	else if (fir > sec && sec > thi)
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

int	find_min_idx(t_list **a)
{
	int		i;
	int		idx;
	long	min;
	t_list	*tmp;

	i = 0;
	idx = 0;
	min = (*a)->content;
	tmp = *a;
	while (tmp != NULL)
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

static void	for_four(t_list **a, t_list **b, int i)
{
	int	idx;
	int ret;

	idx = find_min_idx(a);
	if (idx <= i / 2)
	{
		while (idx-- > 0)
			ra(a);
	}
	else
	{
		ret = i - idx;
		while (ret-- > 0)
			rra(a);
	}
	pb(b, a);
	for_three(a);
	pa(a, b);
}

void	sorting(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	if (i == 1)
		exit(0);
	else if (i == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		exit(0);
	}
	else if (i == 3)
		for_three(a);
	else if (i == 4)
		for_four(a, b, i);
	else if (i < 8)
		for_little(a, b);
	else
		big_sort(a, b);
}
