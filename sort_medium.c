/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/13 16:59:33 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_chunk_move(t_stack *a, int low, int high)
{
	t_stack	*node;
	int		top;
	int		bottom;

	node = a;
	top = 0;
	while (node->index < low || node->index >= high)
	{
		node = node->next;
		top++;
	}
	node = a->prev;
	bottom = 1;
	while (node->index < low || node->index >= high)
	{
		node = node->prev;
		bottom++;
	}
	if (top <= bottom)
		return (top);
	return (-bottom);
}

static void	push_chunk(t_stack **a, t_stack **b, int low, int high)
{
	int	mid;
	int	pushed;
	int	rank;

	mid = low + (high - low) / 2;
	pushed = 0;
	while (pushed < high - low)
	{
		rotate_a_by(a, find_chunk_move(*a, low, high));
		rank = (*a)->index;
		pb(a, b);
		if (rank < mid && (*b)->next != *b)
			rb(b);
		pushed++;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, int size)
{
	int	pos;

	while (size > 0)
	{
		pos = find_index_pos(*b, size - 1);
		if (pos <= size - pos)
			rotate_b_by(b, pos);
		else
			rotate_b_by(b, pos - size);
		pa(a, b);
		size--;
	}
}

void	sort_medium(t_stack **a, t_stack **b, int count)
{
	int	chunk_size;
	int	low;
	int	high;

	if (!*a || count < 2)
		return ;
	rank_stack(*a, count);
	chunk_size = count / chunk_count(count);
	low = 0;
	while (low < count)
	{
		high = low + chunk_size;
		if (high > count || count - high < chunk_size)
			high = count;
		push_chunk(a, b, low, high);
		low = high;
	}
	push_back_to_a(a, b, count);
}
