/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/18 17:23:59 by mehaslan         ###   ########.fr       */
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
	int		*counts;
	char	*name;

	counts = op_counts();
	name = op_name(op);
	counts[op]++;
	ft_putendl_fd(name, 1);
}
