/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 01:18:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/11/17 08:43:44 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_data *data, char **args)
{
	if (args)
		free_args(args);
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_data(t_data *data)
{
	if (data && data->numbers)
	{
		free(data->numbers);
		data->numbers = NULL;
	}
}

void	free_args(char **args)
{
	char	**tmp;

	if (!args)
		return ;
	tmp = args;
	while (*tmp)
		free(*tmp++);
	free(args);
}
