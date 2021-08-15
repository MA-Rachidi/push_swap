/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:39:16 by mohamed           #+#    #+#             */
/*   Updated: 2021/08/15 15:49:32 by mohamed          ###   ########.fr       */
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
        count = len / 5;
    else
        count = len / 4;
    len = len - count;
    val = find_min(*a);
    val = find_center(*a, count, val);
    while (i < count)
    {    
        while ((*a)->val >= val)
            ra(a);
        pb(a, b);
        i++;   
    }
    i = 3;
    if (count != 0)
        find_pass_b(a, b, len);
    else
        while (0 < i--)
            pb(a, b);  
}

void    if_first_suivie(t_node **head)
{
    int val;

    val = (*head)->prev->val;
    val = find_center_max(*head, 1, val);
    while ((*head)->val == val || (*head)->next->val == val)
    {
        if ((*head)->val == val)
            rb(head);
        else
            sb(head), rb(head);
        val = (*head)->prev->val;
        if (val == find_min(*head))
            break;
        val = find_center_max(*head, 1, val);
    }
}