/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:44 by mrachidi          #+#    #+#             */
/*   Updated: 2021/08/15 15:15:00 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {

	int	val;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
int	ft_atoi(char *str);
void	list_insert_end(t_node **head, int val);
void	list_insert_first(t_node **head, int val);
void	error_exit(char	*str, int len);
void	free_list(t_node *head);
void	check_duplicate(t_node *head, int len);
int	check_sorting(t_node *head);
void	list_delete_fist(t_node **head);
int	find_min(t_node *head);
int	find_max(t_node *head);
int	find_center(t_node *head, int len, int min);
void	find_pass_b(t_node **a, t_node **b, int len);
int	find_center_max(t_node *head, int len, int max);
void	if_first_suivie(t_node **head);
int	first3_pa(t_node **a, t_node **b);
int	pa3_to_a(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	algo_sort(t_node **a, t_node **b, int ind);


#endif

