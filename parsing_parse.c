/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:29:27 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/19 02:39:26 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_data (t_data *data)
{
    data->numbers = NULL;
	data->count = 0;
	data->is_bench = 0;
	data->strategy = STR_ADAPTIVE;
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
}

void control_flags(char *str, t_data *data)
{
    if(ft_strcmp(str, "--simple") == 0)
        data->strategy = STR_SIMPLE;
    else if(ft_strcmp(str, "--medium") == 0)
        data->strategy = STR_MEDIUM;
    else if(ft_strcmp(str, "--complex") == 0)
        data->strategy = STR_COMPLEX;
    else if(ft_strcmp(str, "--adaptive") == 0)
        data->strategy = STR_ADAPTIVE;
    else if (ft_strcmp(str, "--bench") == 0)
        data->is_bench = 1;
    else
        write(2, "Error\n", 6); //error function w free n exit
}

void control_numbers(char *str, t_data *data)
{
    int i;
    char **args;
    long nbr;
    
    i = 0;
    args = ft_split(str, ' ');
    if(!args || !args[0])
        write(2, "Error\n", 6); //error function w free n exit
    while(args[i])
    {
        if(is_valid_numbers(args[i]) == 0)
            write(2, "Error\n", 6); //error function w free n exit
        nbr = atol(args[i]);
        if (nbr < -2147483648 || nbr > 2147483647)
			write(2, "Error\n", 6); //error function w free n exit
        //duplicate control
        //save the number to data
        i++;
    }
    //free function for args
}

int is_valid_numbers(char *str)
{
    if(*str == '+' || *str == '-')
        str++;
    if (!*str)
		return (0);
    while(*str)
    {
        if (*str < '0' || *str > '9')
			return (0);
        str++;
    }
    return(1);
}