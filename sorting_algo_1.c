/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:43:26 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/18 11:41:17 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_3(t_node **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val > (*a)->prev->val)
		sa(a), rra(a);
	if ((*a)->val < (*a)->next->val && (*a)->next->val > (*a)->prev->val)
		sa(a), ra(a);
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->prev->val)
		ra(a);
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->prev->val)
		sa(a);
	if ((*a)->val > (*a)->prev->val && (*a)->val < (*a)->next->val)
		rra(a);
}

void	sort_3_of_5(t_node **a, t_node **b)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val > (*a)->prev->val)
	{
		if ((*b)->val < (*b)->next->val)
			ss(a, b), rra(a);
		else
			sa(a), rra(a);
	}
	if ((*a)->val < (*a)->next->val && (*a)->next->val > (*a)->prev->val)
	{
		if ((*b)->val < (*b)->next->val)
			ss(a, b), ra(a);
		else
			sa(a), ra(a);
	}
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->prev->val)
		ra(a);
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->prev->val)
		sa(a);
	if ((*a)->val > (*a)->prev->val && (*a)->val < (*a)->next->val)
		rra(a);
}

void	sort_5(t_node **a, t_node **b)
{
	int	i;
	int	min;
	
	i = 0;
	min = find_min(*a);
    min = find_center(*a, 2, min);
    while (i++ < 2)
    {    
        while ((*a)->val >= min)
            ra(a);
        pb(a, b);   
    }
	sort_3_of_5(a, b);
	if ((*b)->val < (*b)->next->val)
		sb(b);
	pa(a, b), pa(a, b); 
}

void	sort_up_3(t_node **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val > (*a)->next->next->val)
		sa(a), ra(a), sa(a), rra(a), sa(a);
	if ((*a)->val < (*a)->next->val && (*a)->next->val > (*a)->next->next->val &&
		(*a)->val < (*a)->next->next->val)
		ra(a), sa(a), rra(a);
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val &&
		(*a)->val > (*a)->next->next->val)
		sa(a), ra(a), sa(a), rra(a);
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val &&
		(*a)->val < (*a)->next->next->val)
		sa(a);
	if ((*a)->val < (*a)->next->val && (*a)->next->next->val < (*a)->next->val &&
		(*a)->val > (*a)->next->next->val)
		ra(a), sa(a), rra(a), sa(a);
}

void	algo_sort(t_node **a, t_node **b, int len, int ind)
{
	static int	j = 0;

	if (ind == 0)
	{
		j = first3_pa(a, b);
		sort_3(a);
	}
	if (ind == 1)
	{
		j = pa3_to_a(a, b, j);
		sort_up_3(a);
	}
	j = if_first_suivie(a, b, j);
	if (*b != NULL)
		algo_sort(a, b, len, 1);
}