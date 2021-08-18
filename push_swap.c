/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:42:04 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/18 11:40:21 by mohamed          ###   ########.fr       */
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

int list_lenght(t_node *head)
{
    int i;
    t_node *curr;
    t_node *tail;

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
	check_duplicate(node, ac - 1);
	if (ac == 4)
		sort_3(&node);
	else if (ac == 6)
	{
		printf ("HELLO\n");
		sort_5(&node, &b);
	}
	else
	{
		find_pass_b(&node, &b, ac - 1);
		algo_sort(&node, &b,ac - 1, 0);
	}
	free_list(node);
	free_list(b);
	return (0);
}
