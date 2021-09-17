/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:06:42 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/15 10:53:34 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, int i)
{
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (i == 1)
		write (1, "ra\n", 3);
}

void	rb(t_node **b, int i)
{
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	if (i == 1)
		write (1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int i)
{
	if (*a == NULL || *b == NULL)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
	if (i == 1)
		write (1, "rr\n", 3);
}

void	rra(t_node **a, int i)
{
	if (*a == NULL)
		return ;
	*a = (*a)->prev;
	if (i == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_node **b, int i)
{
	if (*b == NULL)
		return ;
	*b = (*b)->prev;
	if (i == 1)
		write (1, "rrb\n", 4);
}
