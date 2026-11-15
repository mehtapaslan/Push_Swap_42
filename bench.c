/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/15 17:58:58 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_disorder(double disorder)
{
	int	n;

	n = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(n / 100, 2);
	ft_putchar_fd('.', 2);
	if (n % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	put_strategy(t_strategy strategy, double disorder)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (strategy == STR_SIMPLE)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (strategy == STR_MEDIUM)
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (strategy == STR_COMPLEX)
		ft_putendl_fd("Complex / O(n log n)", 2);
	else if (disorder < 0.2)
		ft_putendl_fd("Adaptive / O(n^2)", 2);
	else if (disorder < 0.5)
		ft_putendl_fd("Adaptive / O(n√n)", 2);
	else
		ft_putendl_fd("Adaptive / O(n log n)", 2);
}

static int	total_ops(void)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += op_counts()[i++];
	return (total);
}

static void	put_op_line(t_op from, t_op to)
{
	ft_putstr_fd("[bench] ", 2);
	while (from <= to)
	{
		ft_putstr_fd(op_name(from), 2);
		ft_putstr_fd("  ", 2);
		ft_putnbr_fd(op_counts()[from], 2);
		ft_putstr_fd("  ", 2);
		from++;
	}
	ft_putchar_fd('\n', 2);
}

/*
** disorder must be computed before sorting (on the initial stack a).
** Everything is written to stderr so stdout keeps only the operations.
*/
void	print_bench(t_strategy strategy, double disorder)
{
	put_disorder(disorder);
	put_strategy(strategy, disorder);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putchar_fd('\n', 2);
	put_op_line(OP_SA, OP_PB);
	put_op_line(OP_RA, OP_RRR);
}
