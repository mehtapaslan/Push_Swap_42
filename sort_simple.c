/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:22 by beakduma          #+#    #+#             */
/*   Updated: 2026/10/23 22:23:59 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_stack *a, int size)
{
	t_stack	*current;
	int		min_value;
	int		min_index;
	int		i;

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

/*
** Sorts 2 or 3 elements in at most 2 operations:
** biggest goes to the bottom first (ra / rra), then the top two are fixed.
*/
static void	sort_three(t_stack **a, int size)
{
	t_stack	*top;

	if (size == 3)
	{
		top = *a;
		if (top->value > top->next->value && top->value > top->prev->value)
			ra(a);
		else if (top->next->value > top->value
			&& top->next->value > top->prev->value)
			rra(a);
	}
	if (size >= 2 && (*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_simple(t_stack **a, t_stack **b, int count)
{
	int	remaining;
	int	min_index;
	int	rra_count;

	remaining = count;
	while (remaining > 3)
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
	sort_three(a, remaining);
	while (*b)
		pa (a, b);
}
