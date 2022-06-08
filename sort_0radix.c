/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_0radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_pbrb(t_data *data, int radix, char *upstr, char *downstr)
{
	int	digit;

	digit = radix_digit(data->stack_a->top->index, radix);
	while (digit_in_str(digit, upstr))
	{
		pb(data->stack_a, data->stack_b, &data->nmoves);
		digit = radix_digit(data->stack_a->top->index, radix);
	}
	while (digit_in_str(digit, downstr))
	{
		pb(data->stack_a, data->stack_b, &data->nmoves);
		digit = radix_digit(data->stack_a->top->index, radix);
		if ((digit_in_str(digit, upstr) != 1)
			&& (digit_in_str(digit, downstr) != 1))
		{
			rr(data->stack_a, data->stack_b, &data->nmoves);
			digit = radix_digit(data->stack_a->top->index, radix);
		}
		else
			rb(data->stack_b, &data->nmoves);
	}
}

void	pb_pbrb_short(t_data *data, int radix, char *upstr, char *downstr)
{
	int	digit;

	while (numstrs_in_stack(data->stack_a, radix, upstr, downstr) == 1)
	{
		digit = radix_digit(data->stack_a->top->index, radix);
		while (digit_in_str(digit, upstr) != 1
			&& digit_in_str(digit, downstr) != 1)
		{
			ra(data->stack_a, &data->nmoves);
			digit = radix_digit(data->stack_a->top->index, radix);
		}
		pb_pbrb(data, radix, upstr, downstr);
	}
}

void	pa_para(t_data *data, int radix, int upnum, int downnum)
{
	int	digit;

	digit = radix_digit(data->stack_b->top->index, radix);
	while (digit == upnum || digit == downnum)
	{
		while (digit == upnum)
		{
			pa(data->stack_a, data->stack_b, &data->nmoves);
			digit = radix_digit(data->stack_b->top->index, radix);
		}
		while (digit == downnum)
		{
			pa(data->stack_a, data->stack_b, &data->nmoves);
			ra(data->stack_a, &data->nmoves);
			digit = radix_digit(data->stack_b->top->index, radix);
		}
	}
}

void	pa_para_rb0(t_data *data, int radix, int upnum, int downnum)
{
	int	digit;

	digit = radix_digit(data->stack_b->top->index, radix);
	while (digit == upnum || digit == downnum || digit == 0)
	{
		while (digit == upnum)
		{
			pa(data->stack_a, data->stack_b, &data->nmoves);
			digit = radix_digit(data->stack_b->top->index, radix);
		}
		while (digit == downnum)
		{
			pa(data->stack_a, data->stack_b, &data->nmoves);
			ra(data->stack_a, &data->nmoves);
			digit = radix_digit(data->stack_b->top->index, radix);
		}
		while (digit == 0)
		{
			rb(data->stack_b, &data->nmoves);
			digit = radix_digit(data->stack_b->top->index, radix);
		}
	}
}

void	sort_no_order(t_data *data, int radix)
{
	pb_pbrb_short(data, radix, "037", "28");
	pb_pbrb_short(data, radix, "64", "19");
	pa_para(data, radix, 4, 6);
	pa_para_rb0(data, radix, 3, 7);
	pa_para(data, radix, 2, 8);
	pa_para(data, radix, 1, 9);
	paall(data);
}
