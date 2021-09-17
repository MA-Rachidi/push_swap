/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:49:56 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/16 15:41:05 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_string_help(char *str, int i, t_node **a, t_node **b)
{
	int		j;
	char	s[5];

	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			s[j] = '\0';
			if (what_operation(s, a, b) == 0)
				return (0);
			j = 0;
		}
		else
		{
			if (j > 2)
				return (0);
			s[j] = str[i];
			j++;
		}
		i++;
	}
	free_list(*b);
	free(str);
	return (1);
}

int	correct_string(char *str, t_node **a)
{
	int		i;
	t_node	*b;

	b = NULL;
	i = ft_strlen(str);
	if (str[i - 1] != '\n')
		return (0);
	i = 0;
	return (correct_string_help(str, i, a, &b));
}

int	get_strhelp(int i, char *c, char *str, t_node **a)
{
	while (i > 0)
	{
		str = ft_strjoin(str, c);
		c = malloc(2);
		i = read(0, c, 1);
		if (i == -1)
		{
			free(c);
			return (0);
		}
		c[1] = '\0';
	}
	free(c);
	return (correct_string(str, a));
}

int	get_string(t_node **a)
{
	char	*c;
	char	*str;
	int		i;

	c = malloc(2);
	i = read(0, c, 1);
	if (i == 0 || i == -1)
	{
		free(c);
		return (0);
	}
	c[1] = '\0';
	str = malloc(1);
	str[0] = '\0';
	return (get_strhelp(i, c, str, a));
}

int	main(int ac, char **av)
{
	t_node	*node;
	int		i;

	node = NULL;
	i = 0;
	if (ac <= 2)
		exit(1);
	while (++i < ac)
		list_insert_end(&node, ft_atoi(av[i]));
	if (check_sorting(node) == 1)
		write(1, "OK\n", 3), exit(1);
	check_duplicate(node, ac - 1);
	i = get_string(&node);
	if (i == 0)
		error_exit("Error\n", 6);
	check_sorting_bns(node);
	free_list(node);
	return (0);
}
