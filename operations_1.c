/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:14 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/15 10:50:35 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head, int i)
{
	int	temp;

	if (list_lenght(*head) < 2)
		return ;
	temp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = temp;
	if (i == 1)
		write (1, "sa\n", 3);
}

void	sb(t_node **head, int i)
{
	int	temp;

	if (list_lenght(*head) < 2)
		return ;
	temp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = temp;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int i)
{
	int	temp;

	if (list_lenght(*a) < 2 || list_lenght(*b) < 2)
		return ;
	temp = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = temp;
	temp = (*b)->val;
	(*b)->val = (*b)->next->val;
	(*b)->next->val = temp;
	if (i == 1)
		write (1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b, int i)
{
	if (*b == NULL)
		return ;
	list_insert_first(a, (*b)->val);
	list_delete_fist(b);
	if (i == 1)
		write (1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int i)
{
	if (*a == NULL)
		return ;
	list_insert_first(b, (*a)->val);
	list_delete_fist(a);
	if (i == 1)
		write (1, "pb\n", 3);
}
