/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:29:27 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/23 03:32:34 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void control_flags(char *str, t_data *data)
{
    if (data->count > 0)
        error_exit(data, NULL);
    if (ft_strncmp(str, "--bench", 8) == 0)
    {
        if(data->is_bench != 0)
		    error_exit(data, NULL);
        data->is_bench = 1;
    }
    else
        set_strategy(str, data);
   
}

void set_strategy(char *str, t_data *data)
{
    if(data->strategy == STR_NONE)
    {
        if(ft_strncmp(str, "--simple", 9) == 0)
            data->strategy = STR_SIMPLE;
        else if(ft_strncmp(str, "--medium", 9) == 0)
            data->strategy = STR_MEDIUM;
        else if(ft_strncmp(str, "--complex", 10) == 0)
            data->strategy = STR_COMPLEX;
        else if(ft_strncmp(str, "--adaptive", 11) == 0)
            data->strategy = STR_ADAPTIVE;
        else
            error_exit(data, NULL);
    }
    else
        error_exit(data, NULL);
}