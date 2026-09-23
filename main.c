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

	if (argc < 2)
		return (0);
	init_data(&data);
	parse_args(argc, argv, &data);
	a = build_stack(data.numbers, data.count);
	if (!a)
		return (1);
	b = NULL;
	free_data(&data);

	//algorithms and strategies
	
	free_stack(&a);
	return(0);
}