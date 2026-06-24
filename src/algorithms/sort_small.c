/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:42:40 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/14 23:25:27 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *stack, int is_print)
{
	if (stack->a->rank > stack->a->next->rank)
		sa(stack, 1, is_print);
}

void	sort_3(t_data *stack, int is_print)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->rank;
	b = stack->a->next->rank;
	c = stack->a->next->next->rank;
	if (a > b && b < c && a < c)
		sa(stack, 1, is_print);
	else if (a > b && b > c)
	{
		sa(stack, 1, is_print);
		rra(stack, 1, is_print);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1, is_print);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1, is_print);
		ra(stack, 1, is_print);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1, is_print);
}

void	sort_4(t_data *stack, int is_print)
{
	int	pos;

	pos = find_min_pos(stack->a);
	if (pos == 1)
		sa(stack, 1, is_print);
	else if (pos == 2)
	{
		ra(stack, 1, is_print);
		ra(stack, 1, is_print);
	}
	else if (pos == 3)
		rra(stack, 1, is_print);
	pb(stack, is_print);
	sort_3(stack, is_print);
	pa(stack, is_print);
}

void	sort_5(t_data *stack, int is_print)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack->a->rank == 0 || stack->a->rank == 1)
		{
			pb(stack, is_print);
			i++;
		}
		else
			ra(stack, 1, is_print);
	}
	sort_3(stack, is_print);
	if (stack->b->rank < stack->b->next->rank)
		sb(stack, 1, is_print);
	pa(stack, is_print);
	pa(stack, is_print);
}

void	sort_small(t_data *stack, int size, int is_print)
{
	if (size == 2)
		sort_2(stack, is_print);
	else if (size == 3)
		sort_3(stack, is_print);
	else if (size == 4)
		sort_4(stack, is_print);
	else if (size == 5)
		sort_5(stack, is_print);
}
