/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:06:42 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/25 21:55:06 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node *a)
{
	a = a->next;
	write (1, "ra\n", 3);
}

void	rb(t_node *b)
{
	b = b->next;
	write (1, "rb\n", 3);
}
void	r(t_node *a, t_node *b)
{
	a = a->next;
	b = b->next;
	write (1, "rr\n", 3);
}
