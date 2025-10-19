#include "push_swap.h"

int	smallest_max(t_list **a, int b_val) //26 satır diyor
{
	t_list	*tmp;
	long		max;

	max = 2147483648;
	tmp = (*a);
	while (tmp)
	{
		if (b_val < tmp->index)
		{
			if (max > tmp->index)
				max = tmp->index;
		}
		tmp = tmp->next;
	}
	if (max == 2147483648)
	{
		tmp = (*a);
		max = tmp->index;
		while (tmp)
		{
			if (tmp->index < max)
				max = tmp->index;
			tmp = tmp->next;
		}
	}
	return (max);
}

void best_move_b(t_list **a, t_list **b, int size_b)
{
	int max;
	int b_max;
	int rep;
	t_list *tmp;

	tmp = (*b);
	max = tmp->index;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	b_max = find_pos(b, max);
	if (b_max > size_b / 2)
	{
		rep = size_b - b_max;
		while (rep-- > 0)
			rrb(b);
	}
	else
		while (b_max-- > 0)
			rb(b);
}