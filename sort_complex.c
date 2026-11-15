/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:48 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/15 20:18:22 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_b(t_stack **a, t_stack **b, int bit, int count)
{
	int	ones;

	ones = 0;
	while (count--)
	{
		if (((*b)->index >> bit) & 1)
		{
			pa(a, b);
			ones++;
		}
		else
			rb(b);
	}
	return (ones);
}

static int	process_a(t_stack **a, t_stack **b, int bit, int count)
{
	int	pushed;

	pushed = 0;
	while (count--)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
		{
			pb(a, b);
			pushed++;
		}
	}
	return (pushed);
}

void	sort_complex(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	bit;
	int	nb;
	int	ones;
	int	pushed;

	if (index_stack(*a, size) == -1)
		return ;
	max_bits = get_max_bits(size);
	bit = 0;
	nb = 0;
	while (bit < max_bits)
	{
		ones = process_b(a, b, bit, nb);
		pushed = process_a(a, b, bit, size - nb + ones);
		nb = nb - ones + pushed;
		bit++;
	}
	while (*b)
		pa(a, b);
}
