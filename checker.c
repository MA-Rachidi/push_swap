/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:49:56 by mrachidi          #+#    #+#             */
/*   Updated: 2021/06/11 16:55:54 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	//int		*b;
	int		i;
	int		j;
	//char	buff[4];

	j = 0;
	i = 0;
	if (argc == 0)
		exit (1);
	printf ("%s\n", argv[3]);
	return (0);
}
