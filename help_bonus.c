/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:25:37 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/13 15:57:51 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char	*str, int len)
{
	write(1, str, len);
	exit(0);
}

void	free_list(t_node *head)
{
	t_node	*tmp;
	t_node	*tail;

	if (head == NULL)
		return ;
	tail = head->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(tail);
}

void	list_insert_end(t_node **head, int value)
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
}

void	check_duplicate(t_node *head, int len)
{
	int		i;
	int		j;
	int		x;
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
