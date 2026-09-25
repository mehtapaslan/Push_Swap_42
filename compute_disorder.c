/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:53:55 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/26 02:18:57 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  every_pairs (t_stack *tmp)
{
    t_stack *sec;
    int mistakes;

    sec = tmp->next;
    mistakes = 0;
    while (sec)
    {
        if (tmp->value > sec->value)
            mistakes++;
        sec = sec->next;
    }
    return (mistakes);
}
double  compute_disorder(t_stack **a, int count)
{
    int    mistakes;
    int total_pairs;
    t_stack *tmp;
    t_stack *last;

    if (!*a || (*a)->next == *a)
        return (0.0);
    last = (*a)->prev;
    last->next = NULL;
    total_pairs = 0;
    mistakes = 0;
    tmp = *a;
    while (tmp)
    {
        mistakes += every_pairs(tmp);
        tmp = tmp->next;
    }
    last->next = *a;
    total_pairs = count * (count - 1) / 2;
    return ((double)mistakes / (double)total_pairs);
}
