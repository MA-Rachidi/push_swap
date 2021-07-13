/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:42:04 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/13 19:01:15 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	list_insert_end(t_node **head, int val)
{
	t_node	*node;
	t_node	*curr;

	node = malloc(sizeof(t_node));
	if (!(node))
		exit(1);
	node->next = NULL;
	node->value = val;
	curr = *head;
	if (*head == NULL)
	{
		*head = node;
		return;
	}
	while (curr != NULL)
		cuur = curr->next;
	curr->next = node;
}

int	main(int ac, char **av)
{
	t_node	*node = NULL;
	
	return (0);
}
