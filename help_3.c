/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:31:21 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/13 10:26:58 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_rb_or_rrb(t_node *head, int j, int max)
{
	int		i;
	int		k;
	int		*ind;
	t_node	*curr;
	int		len;

	i = 0;
	k = 0;
	curr = head;
	ind = malloc(sizeof(int) * 3);
	len = list_lenght(head);
	while (i < 3)
	{
		k++;
		while (curr->val < max)
		{
			k++;
			curr = curr->next;
		}
		ind[i] = check_if_0_1(k, len, j);
		curr = curr->next;
		i++;
	}
	return (ind);
}

int	find_max(t_node *head)
{
	t_node	*curr;
	t_node	*tail;
	int		max;

	max = head->val;
	tail = head->prev;
	curr = head;
	while (curr != tail)
	{
		if (curr->val > max)
			max = curr->val;
		curr = curr->next;
	}
	if (tail->val > max)
		max = tail->val;
	return (max);
}

int	find_center_max(t_node *head, int len, int max)
{
	t_node	*curr;
	t_node	*tail;
	int		ctr;

	tail = head->prev;
	while (0 < len--)
	{
		ctr = head->val;
		curr = head;
		while (ctr >= max)
		{
			ctr = curr->next->val;
			curr = curr->next;
		}
		while (curr != tail)
		{
			if (curr->val > ctr && curr->val < max)
				ctr = curr->val;
			curr = curr->next;
		}
		if (tail->val > ctr && tail->val < max)
			ctr = tail->val;
		max = ctr;
	}
	return (max);
}

int	first3_pa(t_node **a, t_node **b)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = find_max(*b);
	max = find_center_max(*b, 3, max);
	while (i < 3)
	{
		while ((*b)->val <= max)
		{
			rb(b, 1);
			j++;
		}
		pa(a, b, 1);
		i++;
	}
	return (j);
}

int	pa3_to_a(t_node **a, t_node **b, int j)
{
	int	max;
	int	i;
	int	*k;

	i = -1;
	max = (*a)->val;
	max = find_center_max(*b, 3, max);
	k = check_rb_or_rrb(*b, j, max);
	while (++i < 3)
	{
		while ((*b)->val < max && k[i] == 0)
			rb(b, 1), j++;
		while ((*b)->val < max && k[i] == 1)
			rrb(b, 1), j--;
		if (i == 2 && (*a)->val > (*a)->next->val)
			sa(a, 1);
		pa(a, b, 1);
	}
	free(k);
	return (j);
}
