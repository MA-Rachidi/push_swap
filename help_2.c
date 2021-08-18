/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:39:16 by mohamed           #+#    #+#             */
/*   Updated: 2021/08/18 10:46:42 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    list_delete_fist(t_node **head)
{
    t_node  *tail;
    t_node  *curr;
    
    curr = (*head);
    if (*head == (*head)->next)
        *head = NULL;
    else
    {
        tail = (*head)->prev;
        *head = (*head)->next;
        tail->next = *head;
        (*head)->prev = tail;
    }
    free(curr);
}

int find_min(t_node *head)
{
    t_node  *curr;
    t_node  *tail;
    int min;

    min = head->val;
    tail = head->prev;
    curr = head;
    while (curr != tail)
    {
        if (curr->val < min)
            min = curr->val;
        curr = curr->next;
    }
    if (tail->val < min)
        min = tail->val;
    return (min);
}

int find_center(t_node *head, int len, int min)
{
    t_node  *curr;
    t_node  *tail;
    int ctr;

    tail = head->prev;
    while (0 < len--)
    {
        ctr = head->val;
        curr = head;
        while (ctr <= min)
        {   
            ctr = curr->next->val;
            curr = curr->next;
        }
        while (curr != tail)
        {
            if (curr->val < ctr && curr->val > min)
                ctr = curr->val;
            curr = curr->next;
        }
        if (tail->val < ctr && tail->val > min)
            ctr = tail->val;
        min = ctr;
    }
    return (min);
}

void    find_pass_b(t_node **a, t_node **b, int len)
{
    int i;
    int count;
    int val;

    i = 0;
    if (len > 200)
        count = len / 8;
    else if (len > 50)
        count = len / 4;
    else
        count = len / 2;
    len = len - count;
    val = find_min(*a);
    val = find_center(*a, count, val);
    while (i++ < count)
    {    
        while ((*a)->val >= val)
            ra(a);
        pb(a, b);   
    }
    if (count != 0)
        find_pass_b(a, b, len);
    else
        while (*a == NULL)
            pb(a, b);  
}

int if_first_suivie(t_node **a, t_node **b, int j)
{
    int val;

    val = (*a)->val;
    val = find_center_max(*b, 1, val);
    while ((*b)->val == val || (*b)->next->val == val || (*b)->prev->val == val ||
        (*b)->prev->prev->val == val)
    {
        if ((*b)->val == val)
            pa(a, b);
        else if ((*b)->next->val == val)
            sb(b), pa(a, b);
        else if ((*b)->prev->val == val)
            rrb(b), pa(a, b), j--;
        else
        {
            rrb(b), rrb(b), pa(a, b);
            j = j - 2;
        }
        val = (*a)->val;
        if (*b == NULL)
            break;
        val = find_center_max(*b, 1, val);
    }
    return (j);
}