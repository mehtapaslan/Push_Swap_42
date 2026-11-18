/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:36 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/18 17:25:06 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_disorder(double disorder)
{
	int	n;
	int	int_part;
	int	frac_part;

	n = (int)(disorder * 10000 + 0.5);
	int_part = n / 100;
	frac_part = n % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	if (frac_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac_part, 2);
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
	int	*counts;
	int	total;
	int	i;

	counts = op_counts();
	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += counts[i];
		i++;
	}
	return (total);
}

static void	print_op(t_op op)
{
	char	*name;
	int		*counts;

	name = op_name(op);
	counts = op_counts();
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(counts[op], 2);
	ft_putstr_fd("  ", 2);
}

void	print_bench(t_strategy strategy, double disorder, int count)
{
	put_disorder(disorder);
	put_strategy(strategy, disorder, count);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putstr_fd("\n[bench] ", 2);
	print_op(OP_SA);
	print_op(OP_SB);
	print_op(OP_SS);
	print_op(OP_PA);
	print_op(OP_PB);
	ft_putstr_fd("\n[bench] ", 2);
	print_op(OP_RA);
	print_op(OP_RB);
	print_op(OP_RR);
	print_op(OP_RRA);
	print_op(OP_RRB);
	print_op(OP_RRR);
	ft_putstr_fd("\n", 2);
}
