/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:57:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/23 04:25:32 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	*a;
	t_stack	*b;
	double	disorder;

	if (argc < 2)
		return (0);
	init_data(&data);
	parse_args(argc, argv, &data);
	a = build_stack(data.numbers, data.count);
	if (!a)
		error_exit(&data, NULL);
	b = NULL;
	disorder = compute_disorder(&a, data.count);
	if (!is_sorted(data.numbers, data.count))
		sort_stack(&a, &b, data.strategy, data.count);
	if (data.is_bench)
		print_bench(data.strategy, disorder, data.count);
	free_stack(&a);
	free_stack(&b);
	free_data(&data);
	return (0);
}
