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
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	if (swap(b))
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}

// mainde şöyle çağırılacak; sa(&data->a);

