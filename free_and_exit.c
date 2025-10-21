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

void	for_exit(t_list *a)
{
	write(2, "Error\n", 6);
	ft_lstclear(&a);
	exit(1);
}
