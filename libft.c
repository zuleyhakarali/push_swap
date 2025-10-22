/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:19:45 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 19:09:31 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(long content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	lstclear(t_stack **lst)
{
	t_stack	*last;

	if ((lst == NULL) || (*lst == NULL))
		return ;
	last = *lst;
	while (*lst)
	{
		last = (*lst)->next;
		free(*lst);
		*lst = last;
	}
	*lst = NULL;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

int	lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
