/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:57:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/21 15:21:04 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	parse_args(argc, argv, &data);
	// ...
	return (0);
}