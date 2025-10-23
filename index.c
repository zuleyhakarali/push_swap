/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:50:17 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/22 15:54:56 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	in_place_sort(int size, int *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	arr_to_idx(int size, int *arr, t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	indexing(t_stack **stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return ;
	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	in_place_sort(size, arr);
	arr_to_idx(size, arr, stack);
	free(arr);
}
