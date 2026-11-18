/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/18 00:22:21 by mehaslan         ###   ########.fr       */
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

static void	put_strategy(t_strategy strategy, double disorder, int count)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (strategy == STR_SIMPLE)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (strategy == STR_MEDIUM)
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (strategy == STR_COMPLEX)
		ft_putendl_fd("Complex / O(n log n)", 2);
	else if (count <= 5 || disorder < 0.2)
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

static void	put_opr(t_op op)
{
	ft_putstr_fd(op_name(op), 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(op_counts()[op], 2);
	ft_putstr_fd("  ", 2);
}

void	print_bench(t_strategy strategy, double disorder, int count)
{
	put_disorder(disorder);
	put_strategy(strategy, disorder, count);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_opr(OP_SA);
	put_opr(OP_SB);
	put_opr(OP_SS);
	put_opr(OP_PA);
	put_opr(OP_PB);
	ft_putstr_fd("\n[bench] ", 2);
	put_opr(OP_RA);
	put_opr(OP_RB);
	put_opr(OP_RR);
	put_opr(OP_RRA);
	put_opr(OP_RRB);
	put_opr(OP_RRR);
	ft_putstr_fd("\n", 2);
}
