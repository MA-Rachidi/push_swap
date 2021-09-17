/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:37:32 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/16 15:32:03 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	what_operation(char *s, t_node **a, t_node **b)
{
	if (ft_strcmp(s, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(s, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp(s, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(s, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(s, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(s, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(s, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(s, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(s, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(s, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp(s, "rrr") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	list_insert_first(t_node **head, int value)
{
	t_node	*node;
	t_node	*tail;

	node = malloc(sizeof(t_node));
	if (!(node))
		exit(1);
	node->val = value;
	if (*head == NULL)
	{
		node->next = node;
		node->prev = node;
		*head = node;
		return ;
	}
	tail = (*head)->prev;
	node->next = *head;
	(*head)->prev = node;
	node->prev = tail;
	tail->next = node;
	(*head) = node;
}

void	list_delete_fist(t_node **head)
{
	t_node	*tail;
	t_node	*curr;

	curr = (*head);
	if (*head == (*head)->next)
		*head = NULL;
	else
	{
		tail = (*head)->prev;
		*head = (*head)->next;
		tail->next = *head;
		(*head)->prev = tail;
	}
	free(curr);
}

void	check_sorting_bns(t_node *head)
{
	t_node	*curr;
	t_node	*tail;

	curr = head;
	tail = head->prev;
	while (curr != tail)
	{
		if (curr->val > curr->next->val)
			break ;
		curr = curr->next;
	}
	if (curr == tail)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	list_lenght(t_node *head)
{
	int		i;
	t_node	*curr;
	t_node	*tail;

	if (head == NULL)
		return (0);
	i = 1;
	curr = head;
	tail = head->prev;
	while (curr != tail)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
