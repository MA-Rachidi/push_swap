/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:44 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/27 21:12:15 by mrachidi         ###   ########.fr       */
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
void	error_exit(char	*str, int len);
void	free_list(t_node *head, int len);
void	check_duplicate(t_node *head, int len);
void	check_sorting(t_node *head, int len);
void	sort_3(t_node **a);


#endif

