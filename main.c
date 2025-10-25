/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:50:07 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/25 13:16:06 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	repeating_numbers(char **res)
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

static char	**args(int ac, char **av)
{
	char	**res;

	if (is_only_space(av[1]))
		return (NULL);
	if (!is_acceptable_str(av[1]))
		return (NULL);
	if (ac == 2 && ft_strchr(av[1], ' '))
		res = ft_split(av[1], ' ');
	else
		res = &av[1];
	if ((!repeating_numbers(res)) || (!is_acceptable_for_int(res)))
	{
		if (ac == 2 && ft_strchr(av[1], ' '))
			free_s(res);
		return (NULL);
	}
	return (res);
}

static int	is_acceptable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

static t_stack	*making_stack(char **res)
{
	long	val;
	t_stack	*a;
	t_stack	*node;

	a = NULL;
	while (*res)
	{
		val = ft_atoi(*res);
		if (val > 2147483647 || val < -2147483648)
			for_exit(a);
		node = lstnew(val);
		if (!node)
			for_exit(a);
		lstadd_back(&a, node);
		if (!is_acceptable(*res))
			for_exit(a);
		res++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**res;

	b = NULL;
	if (ac == 1)
		return (0);
	res = args(ac, av);
	if (!res || !*res)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = making_stack(res);
	if (ac == 2 && ft_strchr(av[1], ' '))
		free_s(res);
	sorting(&a, &b);
	lstclear(&a);
	return (0);
}
