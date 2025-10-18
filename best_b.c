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
