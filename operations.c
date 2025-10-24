/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:37 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/24 19:11:09 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*fir;
	t_stack	*sec;

	if (!(*a) || !((*a)->next))
		return ;
	fir = *a;
	sec = (*a)->next;
	fir->next = sec->next;
	sec->next = fir;
	*a = sec;
	write(1, "sa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*res;
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	res = *a;
	*a = (*a)->next;
	res->next = NULL;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = res;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*res;
	t_stack	*list;

	if (!(*a) || !(*a)->next)
		return ;
	list = *a;
	while (list->next->next != NULL)
		list = list->next;
	res = list->next;
	list->next = NULL;
	res->next = *a;
	*a = res;
	write(1, "rra\n", 4);
}
