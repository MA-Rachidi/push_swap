#include "push_swap.h"

int find_max(t_node *head)
{
    t_node  *curr;
    t_node  *tail;
    int max;

    max = head->val;
    tail = head->prev;
    curr = head;
    while (curr != tail)
    {
        if (curr->val > max)
            max = curr->val;
        curr = curr->next;
    }
    if (tail->val > max)
        max = tail->val;
    return (max);
}

int find_center_max(t_node *head, int len, int max)
{
    t_node  *curr;
    t_node  *tail;
    int ctr;

    tail = head->prev;
    while (0 < len--)
    {
        ctr = head->val;
        curr = head;
        while (ctr >= max)
        {   
            ctr = curr->next->val;
            curr = curr->next;
        }
        while (curr != tail)
        {
            if (curr->val > ctr && curr->val < max)
                ctr = curr->val;
            curr = curr->next;
        }
        if (tail->val > ctr && tail->val < max)
            ctr = tail->val;
        max = ctr;
    }
    return (max);
}

int    first3_pa(t_node **a, t_node **b)
{
    int max;
    int i;
    int j;


    i = 0;
    j = 0;
    max = find_max(*b);
    max = find_center_max(*b, 3, max);
    while (i < 3)
    {    
        while ((*b)->val <= max)
        {
            rb(b);
            j++;
        }
        pa(a, b);
        i++;   
    }
    return (j);
}

int pa3_to_a(t_node **a, t_node **b)
{
    int max;
    int i;
    int j;


    i = 0;
    j = 0;
    max = (*b)->prev->val;
    max = find_center_max(*b, 3, max);
    while (i < 3)
    {    
        while ((*b)->val < max)
        {
            rb(b);
            j++;
        }
        pa(a, b);
        i++;   
    }
    return (j);
}