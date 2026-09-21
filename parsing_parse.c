/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:29:27 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/22 01:45:05 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void control_flags(char *str, t_data *data)
{
    if(ft_strncmp(str, "--simple", 9) == 0)
        data->strategy = STR_SIMPLE;
    else if(ft_strncmp(str, "--medium", 9) == 0)
        data->strategy = STR_MEDIUM;
    else if(ft_strncmp(str, "--complex", 10) == 0)
        data->strategy = STR_COMPLEX;
    else if(ft_strncmp(str, "--adaptive", 11) == 0)
        data->strategy = STR_ADAPTIVE;
    else if (ft_strncmp(str, "--bench", 8) == 0)
        data->is_bench = 1;
    else
        error_exit(data, NULL);
}

void control_numbers(char *str, t_data *data)
{
    int i;
    char **args;
    long nbr;
    
    i = 0;
    args = ft_split(str, ' ');
    if(!args || !args[0])
        error_exit(data, args);
    while(args[i])
    {
        if(!is_valid_numbers(args[i]))
            error_exit(data, args);
        nbr = atolong(args[i]);
        if (nbr < -2147483648 || nbr > 2147483647)
			error_exit(data, args);
        if(is_duplicate(data->numbers, data->count, (int)nbr))
            error_exit(data, args);
        if (!add_nbr(data, (int)nbr))
            error_exit(data, args);
        i++;
    }
    free_args(args);
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