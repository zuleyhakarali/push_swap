/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:47 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 16:55:45 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	for_exit(t_stack *a)
{
	write(2, "Error\n", 6);
	lstclear(&a);
	exit(1);
}

int	is_acceptable_str(char *str)
{
	int	i;
	int digit;

	i = 0;
	digit = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			digit++;
			i++;
		}
		else if (str[i] == ' ')
			i++;
		else
			return(1);
	}
	if (digit > 10)
		return (1);
	return (0);
}

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			i++;
		tmp = tmp->next;
	}
	if (i != 0)
		return (0);
	return (1);
}
