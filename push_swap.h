/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:44 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/25 19:01:22 by mrachidi         ###   ########.fr       */
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

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
int	ft_atoi(char *str);
void	list_insert_end(t_node **head, int val, int i, int ac);
void	error_exit(char	*str, int len);
void	free_list(t_node *head, int ac);
void	check_duplicate(t_node *head, int len);

#endif

