/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//radix == n --> digit == 10^n * x, where x in {0..9};
// return: x;
int	radix_digit(int num, int radix)
{
	while (radix > 0)
	{
		num = num / 10;
		radix--;
	}
	return (num % 10);
}

void	pa3numsinorder(t_data *data, int radix, int maxnum)
{
	int	digit;
	int	i;

	i = data->stack_b->size;
	while (i > 0)
	{
		digit = radix_digit(data->stack_b->top->index, radix);
		if (digit >= maxnum - 2 && digit <= maxnum)
			pa(data->stack_a, data->stack_b, &data->nmoves);
		else
			rb(data->stack_b, &data->nmoves);
		i--;
	}
}

void	pa2nums(t_data *data, int radix, int num1, int num2)
{
	int	digit;
	int	i;

	i = data->stack_b->size;
	while (i > 0)
	{
		digit = radix_digit(data->stack_b->top->index, radix);
		if (digit == num1 || digit == num2)
			pa(data->stack_a, data->stack_b, &data->nmoves);
		else
			rb(data->stack_b, &data->nmoves);
		i--;
	}
}

void	paall(t_data *data)
{
	while (data->stack_b->size > 0)
		pa(data->stack_a, data->stack_b, &data->nmoves);
}

//for those who came there by (pb+rb);
// topB_to_bottomA: while(stack_b->root == num) {pa(num), ra(num)};
// bottomB_to_topA: while(stack_b->root == num) {rrb(num), pa(num)};
void	rrbpa(t_data *data, int num, int radix)
{
	while (radix_digit(data->stack_b->root->index, radix) == num)
	{
		rrb(data->stack_b, &data->nmoves);
		pa(data->stack_a, data->stack_b, &data->nmoves);
	}
}
