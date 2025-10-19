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

// for main.c;

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

// for big_sort.c;

int	cost_for_b(t_list *node, t_list **a, t_list **b)
{
	int	big_min;
	int	idx_a;
	int	idx_b;
	int	val;

	val = node->index;
	big_min = biggest_min(b, val);
	idx_b = find_idx(b, big_min);
	if (idx_b == -1)
		idx_b = 0;
	idx_a = find_idx(a, val);
	return (idx_a + idx_b);
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
