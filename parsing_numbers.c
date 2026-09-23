/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 01:02:41 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/23 04:23:38 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void control_numbers(char *str, t_data *data)
{
    int i;
    char **args;
    int nbr;
    
    i = 0;
    args = ft_split(str, ' ');
    if(!args || !args[0])
        error_exit(data, args);
    while(args[i])
    {
        if(!is_valid_numbers(args[i]))
            error_exit(data, args);
        if(!atoi_safety(args[i], &nbr))
            error_exit(data, args);
        if(is_duplicate(data->numbers, data->count, nbr))
            error_exit(data, args);
        if (!add_nbr(data, nbr))
            error_exit(data, args);
        i++;
    }
    free_args(args);
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

int is_duplicate (int *nbrs, int count, int nbr)
{
    int i;
    
    i = 0;
    while(i < count)
    {
        if(nbrs[i] == nbr)
            return(1);
        i++;
    }
    return(0);
}

int add_nbr(t_data *data, int nbr)
{
    int *new_arr;
    int i;

    new_arr = malloc(sizeof(int)*(data->count + 1));
    if (!new_arr)
		return (0);
    i = 0;
    while(i < data->count)
    {
        new_arr[i] = data->numbers[i];
        i++;
    }
    new_arr[i] = nbr;
    if (data->numbers)
		free(data->numbers);
    data->numbers = new_arr;
	data->count++;
    return(1);
}

int	atoi_safety(const char *nptr, int *result)
{
	long				nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
        if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
        nbr = (nbr * 10) + (*nptr++ - '0');
        if ((nbr * sign) > 2147483647 || (nbr * sign) < -2147483648)
			return (0);
	}
    *result = nbr * sign;
	return (1);
}