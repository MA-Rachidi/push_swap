/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:10 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/15 15:51:01 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char	*str, int len)
{
	write(1, str, len);
	exit(0);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	nb;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb * sign < -2147483648)
			error_exit("Error\n", 6);
		if (nb * sign > 2147483647)
			error_exit("Error\n", 6);
		i++;
	}
	if (str[i] != '\0')
		error_exit("Error\n", 6);
	return (nb * sign);
}

void	check_duplicate(t_node *head, int len)
{
	int	i;
	int	j;
	int	x;
	t_node	*tmp;
	t_node	*tmp2;

	x = 0;
	i = -1;
	j = -1;
	tmp = head;
	tmp2 = head;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tmp->val == tmp2->val)
				x++;
			tmp2 = tmp2->next;
		}
		j = -1;
		tmp2 = head;
		tmp = tmp->next;
	}
	if (x > len)
		error_exit("Error\n", 6);
}

int	check_sorting(t_node *head)
{
	t_node	*curr;
	t_node	*tail;
	
	curr = head;
	tail = head->prev;
	while (curr != tail)
	{
		if (curr->val < curr->next->val)
			break;
		curr = curr->next;
	}
	if (curr == tail)
		return (1);
	else
		return (0);
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
		return;
	}
	tail = (*head)->prev;
	node->next = *head;
	(*head)->prev = node;
	node->prev = tail;
	tail->next = node;
	(*head) = node;
}