/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:14 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/05 23:06:00 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	int	temp;

	temp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = temp;
	write (1, "sa\n", 3);
}

void	sb(t_node **head)
{
	int	temp;;
	
	temp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = temp;
	write (1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	int	temp;

	temp = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = temp;
	temp = (*b)->val;
	(*b)->val = (*b)->next->val;
	(*b)->next->val = temp;
	write (1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	if (*b == NULL)
		return;
	list_insert_first(a, (*b)->val);
	list_delete_fist(b);
	write (1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	if (*a == NULL)
		return;
	list_insert_first(b, (*a)->val);
	list_delete_fist(a); 
	write (1, "pb\n", 3);
}  
