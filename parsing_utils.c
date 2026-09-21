/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 02:36:28 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/22 01:34:58 by mehaslan         ###   ########.fr       */
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

long	atolong(const char *nptr)
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
        if (nbr > (9223372036854775807L - (*nptr - '0')) / 10)
        {
            if (sign == 1)
                return (2147483648L);
            return (-2147483649L);
        }
		nbr = (nbr * 10) + (*nptr++ - '0');
	}
	return (nbr * sign);
}