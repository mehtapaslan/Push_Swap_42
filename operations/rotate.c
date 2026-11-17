/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 05:21:45 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 06:26:20 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack **a)
{
	rotate(a);
	put_op(OP_RA);
}

void	rb(t_stack **b)
{
	rotate(b);
	put_op(OP_RB);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	put_op(OP_RR);
}
