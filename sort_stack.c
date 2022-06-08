/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	pb3nums(t_data *data, int radix, char *upstr, int i)
{
	int	digit;

	digit = radix_digit(data->stack_a->top->index, radix);
	if (digit_in_str(digit, upstr) == 1)
	{
		pb(data->stack_a, data->stack_b, &data->nmoves);
		i--;
		if (i > 0)
			digit = radix_digit(data->stack_a->top->index, radix);
	}
	return (i);
}

int	pbrbnum(t_data *data, int radix, char *upstr, int *num)
{
	int	digit;
	int	i;

	i = num[1];
	digit = radix_digit(data->stack_a->top->index, radix);
	if (i > 0 && digit == *num)
	{
		pb(data->stack_a, data->stack_b, &data->nmoves);
		i--;
		digit = radix_digit(data->stack_a->top->index, radix);
		if (i > 0 && (digit_in_str(digit, upstr) != 1) && digit != *num)
		{
			rr(data->stack_a, data->stack_b, &data->nmoves);
			digit = radix_digit(data->stack_a->top->index, radix);
			i--;
		}
		else
			rb(data->stack_b, &data->nmoves);
	}
	return (i);
}

void	pb3_pbrb1(t_data *data, int radix, char *upstr, int downnum)
{
	int	i;
	int	digit;
	int	nums[2];

	i = data->stack_a->size;
	while (i > 0)
	{
		digit = radix_digit(data->stack_a->top->index, radix);
		i = pb3nums(data, radix, upstr, i);
		nums[1] = i;
		nums[0] = downnum;
		if (i > 0)
			i = pbrbnum(data, radix, upstr, nums);
		if (i > 0 && (digit_in_str(digit, upstr) != 1) && digit != downnum)
		{
			ra(data->stack_a, &data->nmoves);
			i--;
		}
	}
}

void	sort_2last(t_data *data, int radix, int lessnum)
{
	int	i;

	i = data->stack_a->size;
	while (i > 0)
	{
		if (radix_digit(data->stack_a->top->index, radix) == lessnum)
			pb(data->stack_a, data->stack_b, &data->nmoves);
		else
			ra(data->stack_a, &data->nmoves);
		i--;
	}
	while (radix_digit(data->stack_b->top->index, radix) == lessnum)
		pa(data->stack_a, data->stack_b, &data->nmoves);
}

void	sort_stack(t_data *data)
{
	int	radix;
	int	maxradix;

	maxradix = get_max_radix(data->stack_a->size - 1);
	radix = 0;
	while (radix <= maxradix)
	{
		if (radix == 0)
			sort_no_order(data, radix);
		else
		{
			pb3_pbrb1(data, radix, "024", 6);
			pb3_pbrb1(data, radix, "135", 7);
			sort_2last(data, radix, 8);
			rrbpa(data, 7, radix);
			rrbpa(data, 6, radix);
			pa2nums(data, radix, 5, 4);
			pa2nums(data, radix, 3, 2);
			paall(data);
		}
		radix++;
	}
}
