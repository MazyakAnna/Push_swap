/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	a_stack;
	t_stack	b_stack;

	if (all_ints(argv, argc) == -1)
		return (errors(-1));
	init_structures(&data, &a_stack, &b_stack);
	fill_stack(argv, argc, &a_stack);
	if (no_doubles(&a_stack) == -1)
	{
		clear_stack(&a_stack);
		return (errors(-1));
	}
	index_stack(&a_stack);
	if (stack_sorted(&a_stack) == -1)
	{
		if (a_stack.size < 7)
			sort_small_stack(&data);
		else
			sort_stack(&data);
	}
	clear_stack(&a_stack);
}
