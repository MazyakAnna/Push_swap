/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:40:59 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:41:12 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int *moves)
{
	if (stack_a != NULL && stack_a->size > 1)
		rotate_stack(stack_a);
	*moves = *moves + 1;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int *moves)
{
	if (stack_b != NULL && stack_b->size > 1)
		rotate_stack(stack_b);
	*moves = *moves + 1;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int *moves)
{
	if (stack_a != NULL && stack_a->size > 1)
		rotate_stack(stack_a);
	if (stack_b != NULL && stack_b->size > 1)
		rotate_stack(stack_b);
	*moves = *moves + 1;
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack_a, int *moves)
{
	if (stack_a != NULL && stack_a->size > 1)
		r_rotate_stack(stack_a);
	*moves = *moves + 1;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int *moves)
{
	if (stack_b != NULL && stack_b->size > 1)
		r_rotate_stack(stack_b);
	*moves = *moves + 1;
	write(1, "rrb\n", 4);
}
