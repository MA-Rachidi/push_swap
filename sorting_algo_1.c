/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:43:26 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/15 15:50:17 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_3(t_node **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val > (*a)->prev->val)
	{
		sa(a);
		rra(a);
	}
	if ((*a)->val < (*a)->next->val && (*a)->next->val > (*a)->prev->val)
	{
		sa(a);
		ra(a);
	}
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->prev->val)
		ra(a);
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->prev->val)
		sa(a);
	if ((*a)->val > (*a)->prev->val && (*a)->val < (*a)->next->val)
		rra(a);
}

void	algo_sort(t_node **a, t_node **b, int ind)
{
	int	i;
	int	j;

	i = 0;
	if (ind == 0)
		j = first3_pa(a, b);
	if (ind == 1)
		j = pa3_to_a(a, b);
	sort_3(a);
	while (0 < j--)
		rrb(b);
	while (i++ < 3)
		pb(a, b);
	while (0 < --i)
		rb(b);
	if_first_suivie(b);
	i = check_sorting(*b);
	if (i == 1)
		while ((*b) != NULL)
			pa(a, b);
	if (i == 0)
		algo_sort(a, b, 1);
}