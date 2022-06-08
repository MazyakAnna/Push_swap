/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:48:27 by bmaegan           #+#    #+#             */
/*   Updated: 2021/09/28 21:53:56 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL && stack_b->size > 0)
		stack_push(stack_a, stack_pop(stack_b));
}

/*
** mode == a -> ra (or rb if set stack_b as the first arg);
** mode == r -> rr;
** mode == A -> rra (or rrb if stack_b instead of stack_a);
** mode == R -> rrr;
*/
void	checker_rotate(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if (mode == 'a')
	{
		if (stack_a != NULL && stack_a->size > 1)
			rotate_stack(stack_a);
	}
	else if (mode == 'r')
	{
		checker_rotate(stack_a, stack_b, 'a');
		checker_rotate(stack_b, stack_a, 'a');
	}
	else if (mode == 'A')
	{
		if (stack_a != NULL && stack_a->size > 1)
			r_rotate_stack(stack_a);
	}
	else if (mode == 'R')
	{
		checker_rotate(stack_a, stack_b, 'A');
		checker_rotate(stack_b, stack_a, 'A');
	}
}

//sa, sb or ss -- swaps both args if not 0;
void	checker_swap(t_stack *a, t_stack *b)
{
	if (a != NULL)
		stack_topswap(a);
	if (b != NULL)
		stack_topswap(b);
}

int	checker_sorted(t_stack *a_stack, t_stack *b_stack)
{
	t_elem	*tmp;

	if (b_stack != NULL)
		if (b_stack->size > 0)
			return (-1);
	if (a_stack != NULL)
	{
		tmp = a_stack->root;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
			{
				if (tmp->val > tmp->next->val)
					tmp = tmp->next;
				else
					return (-1);
			}
		}
	}
	return (0);
}
