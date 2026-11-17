/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/22 06:58:37 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*op_counts(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

char	*op_name(t_op op)
{
	static char	*names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	return (names[op]);
}

void	put_op(t_op op)
{
	op_counts()[op]++;
	ft_putendl_fd(op_name(op), 1);
}
