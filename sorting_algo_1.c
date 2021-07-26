/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:43:26 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/26 21:00:44 by mrachidi         ###   ########.fr       */
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
