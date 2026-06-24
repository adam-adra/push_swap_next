/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:37:26 by adadra            #+#    #+#             */
/*   Updated: 2026/01/10 05:27:51 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_strat(t_data *data, int value)
{
	if (data->strategy_set == 1)
		print_error_solo();
	data->strategy = value;
	data->strategy_set = 1;
}

int	parse_flags2(char *argv[], int *c, t_data *data)
{
	if ((ft_strncmp(argv[*c], "--simple", 9)) == 0)
		set_strat(data, 0);
	else if ((ft_strncmp(argv[*c], "--medium", 9)) == 0)
		set_strat(data, 1);
	else if ((ft_strncmp(argv[*c], "--complex", 10)) == 0)
		set_strat(data, 2);
	else if ((ft_strncmp(argv[*c], "--adaptive", 11)) == 0)
		set_strat(data, 3);
	else if ((ft_strncmp(argv[*c], "--bench", 8)) == 0)
	{
		if (data->bench)
			print_error_solo();
		data->bench = 1;
	}
	else if ((ft_strncmp(argv[*c], "--", 2)) == 0)
		print_error_solo();
	else
	{
		*c = 1;
		return (-1);
	}
	return (1);
}
