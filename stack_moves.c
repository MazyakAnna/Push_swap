/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int *moves)
{
	stack_topswap(a);
	*moves = *moves + 1;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, int *moves)
{
	stack_topswap(b);
	*moves = *moves + 1;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int *moves)
{
	stack_topswap(a);
	stack_topswap(b);
	*moves = *moves + 1;
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b, int *moves)
{
	if (b != NULL && b->size > 0)
	{
		stack_push(a, stack_pop(b));
		*moves = *moves + 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b, int *moves)
{
	if (a != NULL && a->size > 0)
	{
		stack_push(b, stack_pop(a));
		*moves = *moves + 1;
		write(1, "pb\n", 3);
	}
}
