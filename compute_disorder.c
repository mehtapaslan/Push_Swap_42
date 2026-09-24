/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:53:55 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/23 16:54:41 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double    compute_disorder(t_stack *a, int count) //count (nodeların sayısı) parsingden gelecek
{
    int    mistakes;
    int    total_pairs;
    int    outer;
    int    inner;
    t_stack    *i;
    t_stack    *j;

    mistakes = 0;
    total_pairs = 0;
    i = a;
    outer = 0;
    while (outer < count)
    {
        j = i->next;
        inner = outer + 1;
        while (inner < count)
        {
            total_pairs += 1;
            if (i->value > j->value)
                mistakes += 1;
            j = j->next;
            inner++;
        }
        i = i->next;
        outer++;
    }
    if (total_pairs == 0)
        return (0.0);
    return ((double)mistakes / (double)total_pairs);
}
