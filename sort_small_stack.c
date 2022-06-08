/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size3(t_stack *stack_a, int *nmoves)
{
	if (stack_a->top->index > stack_a->top->prev->index
		&& stack_a->top->index > stack_a->root->index)
		ra(stack_a, nmoves);
	else if (stack_a->root->index < stack_a->top->prev->index)
		rra(stack_a, nmoves);
	if (stack_a->top->index > stack_a->top->prev->index)
		sa(stack_a, nmoves);
}

void	r_sort_stack_size3(t_stack *stack_b, int *nmoves)
{
	if (stack_b->top->index < stack_b->top->prev->index
		&& stack_b->top->index < stack_b->root->index)
		rb(stack_b, nmoves);
	else if (stack_b->root->index > stack_b->top->prev->index)
		rrb(stack_b, nmoves);
	if (stack_b->top->index < stack_b->top->prev->index)
		sb(stack_b, nmoves);
}

// ok for stacks size 4-6
void	sort_small_stack(t_data *data)
{
	int	median;

	median = data->stack_a->size - 3;
	while (data->stack_a->size > 3)
	{
		if (data->stack_a->top->index >= median)
			ra(data->stack_a, &data->nmoves);
		else
			pb(data->stack_a, data->stack_b, &data->nmoves);
	}
	sort_stack_size3(data->stack_a, &data->nmoves);
	if (data->stack_b->size == 3)
		r_sort_stack_size3(data->stack_b, &data->nmoves);
	else if (data->stack_b->size == 2
		&& data->stack_b->top->index < data->stack_b->root->index)
		sb(data->stack_b, &data->nmoves);
	while (data->stack_b->size > 0)
		pa(data->stack_a, data->stack_b, &data->nmoves);
}
