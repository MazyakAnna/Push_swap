/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits    .c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_doubles(t_stack *stack)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (stack == NULL)
		return (0);
	if (stack->top == NULL)
		return (0);
	tmp1 = stack->top->prev;
	while (tmp1 != NULL)
	{
		tmp2 = stack->top;
		while (tmp2 != tmp1)
		{
			if (tmp1->val == tmp2->val)
				return (-1);
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->prev;
	}
	return (1);
}

void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->nmoves = 0;
}

void	init_structures(t_data *data, t_stack *a_stack, t_stack *b_stack)
{
	init_data(data);
	data->stack_a = a_stack;
	data->stack_b = b_stack;
	init_stack(a_stack);
	init_stack(b_stack);
}

int	errors(int i)
{
	write(1, "Error\n", 6);
	return (i);
}
