/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:42:04 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/15 16:05:26 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// static void	print_list(t_node *head)
// {
// 	t_node *tmp;
// 	t_node	*tail;
// 	int	i = 0;

// 	if (head == NULL)
// 		return;
// 	tail = head->prev;
// 	while (head != tail)
// 	{
// 		tmp = head;
// 		head = head->next;
// 		printf("%d --------> %d\n", i, tmp->val);
// 		i++;
// 	}
// 	printf("%d --------> %d\n", i, tail->val);
// }

void	free_list(t_node *head)
{
	t_node	*tmp;
	t_node	*tail;

	if (head == NULL)
		return;
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
	t_node	*node;
	t_node	*b;
	int	i;

	node = NULL;
	b = NULL;
	i = 0;
	if (ac <= 1)
		exit(1);
	while (++i < ac)
		list_insert_end(&node, ft_atoi(av[i]));
	i = 0;
	//while (++i < 10)
	//	list_insert_end(&b, i);
	check_duplicate(node, ac - 1);
	if (ac == 4)
		sort_3(&node);
	//write (1, "\n\n\n", 3);
	find_pass_b(&node, &b, ac - 1);
	algo_sort(&node, &b, 0);
	//print_list(node);
	//write (1, "\n\n", 2);
	//print_list(b);
	free_list(node);
	//free_list(b);
	return (0);
}
