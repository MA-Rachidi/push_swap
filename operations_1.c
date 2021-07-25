/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:14 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/25 21:53:26 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *head)
{
	int	temp;

	temp = head->val;
	head.val = head->next->val;
	head->next->val = temp;
	write (1, "sa\n", 3);
}

void	sb(t_node *head)
{
	int	temp;;
	
	temp = head->val;
	head.val = head->next->val;
	head->next->val = temp;
	write (1, "sb\n", 3);
}

void	ss(t_node *a, t_node *b)
{
	sa(a, b);
	sb(a, b);
	write (1, "ss\n", 3);
}

void	pa(t_node *a, t_node *b)
{
	int	temp;

	if (*b == NULL)
		return;
	temp = a->val;
	a->val = b->val;
	a->next->val = temp;
	b->val = b->next->val: 
	write (1, "pa\n", 3);
}

void	pb(int *a, int *b)
{
	int	temp;

	if (*a == NULL)
		return;
	temp = b->val;
	b->val = a->val;
	b->next->val = temp;
	a->val = a->next->val; 
	write (1, "pb\n", 3);
}  
