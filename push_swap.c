/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:42:04 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/25 19:38:51 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	free_list(t_node *head, int ac)
{
   t_node *tmp;
   int	i;

   i = 0;
   while (i < ac)
    {
       tmp = head;
       head = head->next;
       free(tmp);
	   i++;
    }
}

void	list_insert_end(t_node **head, int value, int i, int ac)
{
	t_node	*node;
	t_node	*curr;

	node = malloc(sizeof(t_node));
	if (!(node))
		exit(1);
	node->next = NULL;
	node->val = value;
	curr = *head;
	if (*head == NULL)
	{
		*head = node;
		(*head)->prev = NULL;
		return;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
	node->prev = curr;
	if (i == ac - 1)
	{
		(*head)->prev = node;
		node->next = *head;
	}
}

int	main(int ac, char **av)
{
	t_node	*node = NULL;
	int	i;

	i = 0;
	if (ac <= 1)
		exit(1);
	while (++i < ac)
		list_insert_end(&node, ft_atoi(av[i]), i, ac);
	check_duplicate(node, ac - 1);
	free_list(node, ac - 1);
	return (0);
}
