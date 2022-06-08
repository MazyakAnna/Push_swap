/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:01 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:14 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		stack->top = NULL;
		stack->root = NULL;
		stack->size = 0;
	}
}

void	fill_stack(char **args, int argc, t_stack *stack)
{
	int	i;

	if (stack != NULL && args != NULL)
	{
		stack->size = 0;
		i = argc;
		while (i > 1)
		{
			stack_push(stack, create_elem(ft_atoi(args[i - 1])));
			i--;
		}
	}
}

int	stack_sorted(t_stack *stack)
{
	t_elem	*tmp;

	if (stack == NULL)
		return (0);
	if (stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->prev != NULL)
	{
		if (tmp->val > tmp->prev->val)
			return (-1);
		tmp = tmp->prev;
	}
	return (1);
}

void	clear_stack(t_stack *stack)
{
	t_elem	*tmp;

	if (stack != NULL)
	{
		tmp = stack->top;
		while (tmp != NULL)
			tmp = del_elem(tmp);
	}
}

int	numstrs_in_stack(t_stack *stack, int radix, char *numstr1, char *numstr2)
{
	t_elem	*tmp;
	int		digit;

	if (stack == NULL)
		return (0);
	tmp = stack->top;
	while (tmp != NULL)
	{
		digit = radix_digit(tmp->index, radix);
		if ((digit_in_str(digit, numstr1) == 1)
			|| (digit_in_str(digit, numstr2) == 1))
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}
