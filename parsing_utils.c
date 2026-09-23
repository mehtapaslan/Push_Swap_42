/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 02:36:28 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/23 03:36:27 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_data (t_data *data)
{
    data->numbers = NULL;
	data->count = 0;
	data->is_bench = 0;
	data->strategy = STR_NONE;
}

int is_sorted(int *nbrs, int count)
{
    int i;

    i = 0;
    while(i < count-1)
    {
        if(nbrs[i] > nbrs[i+1])
            return(0);
        i++;
    }
    return(1);
}

void parse_args (int argc, char **argv, t_data *data)
{
    int i;

    i = 1;
    while(i < argc)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
            control_flags(argv[i], data);
        else
            control_numbers(argv[i], data);
        i++;
    }
    if(data->count == 0 || is_sorted(data->numbers, data->count))
    {
		free_data(data);
	    exit(0);
    }
    if (data->strategy == STR_NONE)
		data->strategy = STR_ADAPTIVE;
}