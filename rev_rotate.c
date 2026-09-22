/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:22:20 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 06:25:43 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate (t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra (t_stack **a)
{
	rev_rotate (a);
	ft_putendl_fd ("rra", 1);
}

void	rrb (t_stack **b)
{
	rev_rotate (b);
	ft_putendl_fd ("rrb", 1);
}

void	rrr (t_stack **a, t_stack **b)
{
	rev_rotate (a);
	rev_rotate (b);
	ft_putendl_fd ("rrr", 1);
}
