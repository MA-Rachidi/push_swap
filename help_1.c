/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:41:10 by mrachidi          #+#    #+#             */
/*   Updated: 2021/07/15 13:47:07 by mrachidi         ###   ########.fr       */
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

