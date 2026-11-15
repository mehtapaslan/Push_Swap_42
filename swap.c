/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 01:10:07 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 02:35:10 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || (*stack)->next == *stack)
		return (0);
	first = *stack;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		put_op(OP_SA);
}

void	sb(t_stack **b)
{
	if (swap(b))
		put_op(OP_SB);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	put_op(OP_SS);
}
