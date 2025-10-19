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

static int cost_for_a(t_list *chosen, t_list **a, t_list **b)
{
	int idx_a = find_idx(a, smallest_max(a, chosen->index));
	int idx_b = find_pos(b, chosen->index);
	int a_size = ft_lstsize(*a);
	int b_size = ft_lstsize(*b);
	int ra_c = idx_a;
	int rra_c = a_size - idx_a;
	int rb_c = idx_b;
	int rrb_c = b_size - idx_b;
	int cost1;
	int cost2;
	int cost3;
	int cost4;
	int res1;
	int res2;

	cost1 = (ra_c > rb_c) ? ra_c : rb_c;
	cost2 = (rra_c > rrb_c) ? rra_c : rrb_c;
	cost3 = ra_c + rrb_c;
	cost4 = rb_c + rra_c;
	res1 = (cost1 > cost2) ? cost2 : cost1;
	res2 = (cost3 > cost4) ? cost4 : cost3;
	if (res1 < res2)
		return (res1);
	else 
		return (res2);
}

static void placement_for_b(t_list **a, t_list **b, t_list *chosen, int size_a, int size_b)
{
	int	pos_a;
	int	pos_b;

	pos_b = find_pos(b, chosen->index);
	pos_a = find_idx(a, smallest_max(a, chosen->index));

	if (pos_a < size_a / 2 && pos_b < size_b / 2)
		while (pos_a-- > 0 && pos_b-- > 0)
			rr(a, b);
	else if (pos_a >= size_a / 2 && pos_b >= size_b / 2)
		while (pos_a-- > 0 && pos_b-- > 0)
			rrr(a, b);
	else if (pos_a < size_a / 2 && pos_b >= size_b / 2)
	{
		while (pos_a-- > 0)
			ra(a);
		while (pos_b-- > 0)
			rrb(b);
	}
	else
	{
		while (pos_a-- > 0)
			rra(a);
		while (pos_b-- > 0)
			rb(b);
	}
}

void best_move_b(t_list **a, t_list **b)
{
	int cost1;
	int cost2;
	int a_size = ft_lstsize(*a);
	int b_size = ft_lstsize(*b);
	t_list *tmp;
	t_list *chosen;

	chosen = NULL;
	cost2 = 2147483647;
	tmp = (*b);
	while (tmp)
	{
		cost1 = cost_for_a(tmp, a, b);
		if (cost1 < cost2)
		{
			cost2 = cost1;
			chosen = tmp;
		}
		tmp = tmp->next;
	}
	placement_for_b(a, b, chosen, a_size, b_size); 
	pa(a, b);
}