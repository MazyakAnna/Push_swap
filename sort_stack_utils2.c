/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nums_in_stack(t_stack *stack, int radix, char *numstr, int num)
{
	t_elem	*tmp;
	int		digit;

	if (stack == NULL)
		return (0);
	tmp = stack->top;
	while (tmp != NULL)
	{
		digit = radix_digit(tmp->index, radix);
		if ((digit_in_str(digit, numstr) == 1) || digit == num)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

/*
** 0 if num <= 9, 1 if num = [10..99], ...
*/
int	get_max_radix(int num)
{
	int	radix;

	radix = 0;
	while (num > 9)
	{
		num = num / 10;
		radix++;
	}
	return (radix);
}
