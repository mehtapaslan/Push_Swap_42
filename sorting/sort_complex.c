/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:48 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/17 09:08:26 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_b(t_stack **a, t_stack **b, int bit, int count)
{
	int	pushed_a;

	pushed_a = 0;
	while (count--)
	{
		if (((*b)->index >> bit) & 1)
		{
			pa(a, b);
			pushed_a++;
		}
		else
			rb(b);
	}
	return (pushed_a);
}

static int	process_a(t_stack **a, t_stack **b, int bit, int count)
{
	int	pushed_b;

	pushed_b = 0;
	while (count--)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
		{
			pb(a, b);
			pushed_b++;
		}
	}
	return (pushed_b);
}

void	sort_complex(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	bit;
	int	nbr;
	int	pushed_a;
	int	pushed_b;

	if (index_stack(*a, size) == -1)
		return ;
	max_bits = get_max_bits(size);
	bit = 0;
	nbr = 0;
	while (bit < max_bits)
	{
		pushed_a = process_b(a, b, bit, nbr);
		pushed_b = process_a(a, b, bit, size - nbr + pushed_a);
		nbr = nbr - pushed_a + pushed_b;
		bit++;
	}
	while (*b)
		pa(a, b);
}
