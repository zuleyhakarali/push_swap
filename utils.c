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
