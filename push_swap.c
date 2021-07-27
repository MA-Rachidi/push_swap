/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:42:04 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/27 21:15:48 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	print_list(t_node *head, int len)
{
	t_node *tmp;
	int	i;

	i = 0;
	while (i < len)
	{
		tmp = head;
		head = head->next;
		printf("%d --------> %d\n", i, tmp->val);
		i++;
	}
}

void	free_list(t_node *head, int len)
{
	t_node *tmp;
	int	i;

	i = 0;
	while (i < len)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		i++;
	}
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
		return;
	}
	tail = (*head)->prev;
	node->next = *head;
	(*head)->prev = node;
	node->prev = tail;
	tail->next = node;
}

int	main(int ac, char **av)
{
	t_node	*node = NULL;
	int	i;

	i = 0;
	if (ac <= 1)
		exit(1);
	while (++i < ac)
		list_insert_end(&node, ft_atoi(av[i]));
	check_duplicate(node, ac - 1);
	if (ac == 4)
		sort_3(&node);
	//write (1, "\n\n\n", 3);
	print_list(node, ac - 1);
	//check_sorting(node, ac -1);
	free_list(node, ac - 1);
	return (0);
}
