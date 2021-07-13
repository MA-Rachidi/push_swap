/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:44 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/11 18:23:30 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {

	int	value;
	struct node *next;
}				t_node;

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);



#endif

