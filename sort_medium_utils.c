/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 06:58:37 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_stack(t_stack *a, int size)
{
	t_stack	*node;
	t_stack	*other;
	int		i;
	int		j;

	node = a;
	i = 0;
	while (i < size)
	{
		node->index = 0;
		other = a;
		j = 0;
		while (j < size)
		{
			if (other->value < node->value)
				node->index++;
			other = other->next;
			j++;
		}
		node = node->next;
		i++;
	}
}

int	chunk_count(int size)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= size)
		r++;
	r = r / 2;
	if (r < 1)
		r = 1;
	return (r);
}

void	rotate_a_by(t_stack **a, int moves)
{
	while (moves > 0)
	{
		ra(a);
		moves--;
	}
	while (moves < 0)
	{
		rra(a);
		moves++;
	}
}

void	rotate_b_by(t_stack **b, int moves)
{
	while (moves > 0)
	{
		rb(b);
		moves--;
	}
	while (moves < 0)
	{
		rrb(b);
		moves++;
	}
}

int	find_index_pos(t_stack *b, int target)
{
	int	pos;

	pos = 0;
	while (b->index != target)
	{
		b = b->next;
		pos++;
	}
	return (pos);
}
