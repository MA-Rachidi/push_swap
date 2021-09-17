/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:44 by mrachidi          #+#    #+#             */
/*   Updated: 2021/09/15 20:05:20 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

void	sa(t_node **a, int i);
void	sb(t_node **b, int i);
void	ss(t_node **a, t_node **b, int i);
void	pa(t_node **a, t_node **b, int i);
void	pb(t_node **a, t_node **b, int i);
void	ra(t_node **a, int i);
void	rb(t_node **b, int i);
void	rr(t_node **a, t_node **b, int i);
void	rra(t_node **a, int i);
void	rrb(t_node **b, int i);
void	rrr(t_node **a, t_node **b, int i);
int		ft_atoi(char *str);
void	list_insert_end(t_node **head, int val);
void	list_insert_first(t_node **head, int val);
void	error_exit(char	*str, int len);
void	free_list(t_node *head);
void	check_duplicate(t_node *head, int len);
int		check_sorting(t_node *head);
void	list_delete_fist(t_node **head);
int		list_lenght(t_node *head);
int		find_min(t_node *head);
int		find_max(t_node *head);
int		find_center(t_node *head, int len, int min);
void	find_pass_b(t_node **a, t_node **b, int len);
int		find_center_max(t_node *head, int len, int max);
int		if_first_suivie(t_node **a, t_node **b, int j);
int		first3_pa(t_node **a, t_node **b);
int		*check_rb_or_rrb(t_node *head, int j, int max);
int		check_if_0_1(int k, int len, int j);
int		pa3_to_a(t_node **a, t_node **b, int j);
void	sort_2(t_node **a);
void	sort_3(t_node **a);
void	sort_3_of_5(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);
void	sort_up_3(t_node **a);
void	algo_sort(t_node **a, t_node **b, int len, int ind);
int		ft_strlen(char *s);
char	*ft_strdup(const char *s);
char	*returnation(char **s1, char **s2);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcmp(char *s1, char *s2);
void	check_sorting_bns(t_node *head);
int		what_operation(char *s, t_node **a, t_node **b);
int		correct_string_help(char *str, int i, t_node **a, t_node **b);
int		correct_string(char *str, t_node **a);
int		get_strhelp(int i, char *c, char *str, t_node **a);
int		get_string(t_node **a);

#endif
