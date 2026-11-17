/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 05:18:58 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/20 05:18:59 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	separate(t_stack **from, t_stack *node)
{
	if (node->next == node)
		*from = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		*from = node->next;
	}
}

static void	attach(t_stack **to, t_stack *node)
{
	if (!*to)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = *to;
		node->prev = (*to)->prev;
		(*to)->prev->next = node;
		(*to)->prev = node;
	}
	*to = node;
}

static void	move(t_stack **from, t_stack **to)
{
	t_stack	*node;

	node = *from;
	separate(from, node);
	attach(to, node);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	move(b, a);
	put_op(OP_PA);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	move(a, b);
	put_op(OP_PB);
}
