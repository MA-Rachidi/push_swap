/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:47:10 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/15 11:11:52 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0')
		len++;
	p = malloc(len + 1);
	if (!(p))
		return (0);
	i = len;
	len = 0;
	while (len < i)
	{
		p[len] = s[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

char	*returnation(char **s1, char **s2)
{
	char	*p;
	int		j;
	int		h;
	int		i;

	i = ft_strlen(*s1);
	j = ft_strlen(*s2);
	p = malloc(i + j + 1);
	if (p == NULL)
		return (0);
	h = -1;
	while (++h < i)
		p[h] = (*s1)[h];
	i = 0;
	while (i < j)
	{
		p[h] = (*s2)[i];
		h++;
		i++;
	}
	p[h] = '\0';
	free(*s1);
	free(*s2);
	return (p);
}

char	*ft_strjoin(char *str1, char *str2)
{
	if (str1 == 0)
		return (0);
	if (*str1 == '\0' && *str2 == '\0')
	{
		free(str1);
		free(str2);
		return (ft_strdup(""));
	}
	return (returnation(&str1, &str2));
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
