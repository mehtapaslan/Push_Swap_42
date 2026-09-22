/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:22 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 07:42:29 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_minimum (t_stack *a, int size)
{
	t_stack	*current;
	int	min_value;
	int	min_index;
	int	i;

	current = a;
	min_value = current->value;
	min_index = 0;
	i = 0;
	while (i < size)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}
void	sort_simple (t_stack **a, t_stack **b, int count)
{
	int	remaining;
	int	min_index;
	int	rra_count;

	remaining = count;
	while (remaining > 0)
	{
		min_index = find_minimum (*a, remaining);
		if (min_index <= remaining - min_index)
		{
			while (min_index--)
				ra (a);
		}
		else
		{
			rra_count = remaining - min_index;
			while (rra_count--)
				rra (a);
		}
		pb (a, b);
		remaining--;
	}
	while (*b)
		pa (a, b);
}
