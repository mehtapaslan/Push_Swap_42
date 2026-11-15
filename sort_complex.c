/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:48 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/15 03:21:52 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selection_sort(t_stack *arr, int size)
{
	t_stack	*current_arr;
	t_stack	*temp_arr;
	int		remaining;
	int		min_index;
	int		temp;

	current_arr = arr;
	remaining = size;
	while (remaining > 1)
	{
		min_index = find_minimum(current_arr, remaining);
		temp_arr = current_arr;
		while (min_index--)
			temp_arr = temp_arr->next;
		temp = current_arr->value;
		current_arr->value = temp_arr->value;
		temp_arr->value = temp;
		current_arr = current_arr->next;
		remaining--;
	}
}

static void	assign_index(t_stack *a, t_stack *copy, int size)
{
	int		j;
	t_stack	*temp;

	while (size--)
	{
		j = 0;
		temp = copy;
		while (temp->value != a->value)
		{
			j++;
			temp = temp->next;
		}
		a->index = j;
		a = a->next;
	}
}

static int	index_stack(t_stack *a, int size)
{
	t_stack	*copy;

	copy = copy_stack(a, size);
	if (!copy)
		return (-1);
	selection_sort(copy, size);
	assign_index(a, copy, size);
	free_stack(&copy);
	return (0);
}

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max != 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	sort_complex(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	bit;
	int	i;

	max_bits = get_max_bits(size);
	bit = 0;
	if (index_stack(*a, size) == -1)
		return ;
	while (bit < max_bits)
	{
		i = size;
		while (i)
		{
			if ((((*a)->index) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i--;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
