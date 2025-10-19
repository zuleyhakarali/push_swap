/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:49:42 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 20:34:34 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_list
{
    long    content;
    int		index;
    struct s_list   *next;
}                   t_list;

int ft_lstsize(t_list *lst);
char	*ft_strchr(const char *s, int c);
long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst);
t_list *ft_lstnew(long content);
int		main(int ac, char **av);
int		repeating_numbers(char **res);
void	sa(t_list **s_a);
void	sb(t_list **s_b);
void	ss(t_list **s_a, t_list **s_b);
void	pa(t_list **p_a, t_list **stack_b);
void	pb(t_list **p_b, t_list **stack_a);
void	ra(t_list **r_a);
void	rb(t_list **r_b);
void	rr(t_list **r_a, t_list **t_b);
void	rra(t_list **rr_a);
void	rrb(t_list **rr_b);
void	rrr(t_list **rr_a, t_list **rr_b);
void	sorting(t_list **a, t_list **b);
void	for_three(t_list **a);
void	big_sort(t_list **a, t_list **b, int size_a);
int		cost(t_list *node, t_list **a, t_list **b);
int		find_pos(t_list **a, int idx);
int		biggest_min(t_list **b, int a_val);
int		find_idx(t_list **b, int big_min);
void	indexing(t_list **stack);
void	for_exit(t_list *a);
int	smallest_max(t_list **b, int a_val);
void    best_move_b(t_list **a, t_list **b);
int	find_min_idx(t_list **a);
int	cost_for_b(t_list *chosen, t_list **a, t_list **b, int size_a, int size_b);

#endif