/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:14 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/10 20:34:58 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	sa(int *a)
{
	int	temp;

	if ()
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write (1, "sa\n", 3);
}

void	sb(int *b)
{
	int	temp;;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write (1, "sb\n", 3);
}

void	ss(int *a, int *b)
{
	sa(a, b);
	sb(a, b);
	write (1, "ss\n", 3);
}

void	pa(int *a, int *b)
{
	int temp;
	temp = b[0];
}

void	pa(int *a, int *b)
{
	int temp;
	temp = b[0];
}  
