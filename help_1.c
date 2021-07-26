/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:03 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/26 21:06:58 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:10 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/25 20:29:43 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char	*str, int len)
{
	write(1, str, len);
	exit(0);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	nb;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb * sign < -2147483648)
			error_exit("Error\n", 6);
		if (nb * sign > 2147483647)
			error_exit("Error\n", 6);
		i++;
	}
	if (str[i] != '\0')
		error_exit("Error\n", 6);
	return (nb * sign);
}

void	check_duplicate(t_node *head, int len)
{
	int	i;
	int	j;
	int	x;
	t_node	*tmp;
	t_node	*tmp2;

	x = 0;
	i = -1;
	j = -1;
	tmp = head;
	tmp2 = head;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tmp->val == tmp2->val)
				x++;
			tmp2 = tmp2->next;
		}
		j = -1;
		tmp2 = head;
		tmp = tmp->next;
	}
	if (x > len)
		error_exit("Error\n", 6);
}

void	check_sorting(t_node *head, int len)
{
	int	i;

	i = 1;
	while (i <= len)
	{
		if (head->val > head->next->val)
			break;
		head = head->next;
		i++;
	}
	if (i == len)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
