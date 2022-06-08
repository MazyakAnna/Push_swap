/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:55:03 by bmaegan           #+#    #+#             */
/*   Updated: 2021/09/28 23:19:45 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_command_2(char *line, t_data *data,
	t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(line, "sa", 3))
		stack_topswap(data->stack_a);
	else if (!ft_strncmp(line, "sb", 3))
		stack_topswap(data->stack_b);
	else if (!ft_strncmp(line, "ss", 3))
		checker_swap(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", 3))
		checker_push(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb", 3))
		checker_push(stack_b, stack_a);
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	checker_command(char *line, t_data *data,
	t_stack *stack_a, t_stack *stack_b)
{
	if (line == NULL)
		return (0);
	if (!ft_strncmp(line, "ra", 3))
		checker_rotate(stack_a, stack_b, 'a');
	else if (!ft_strncmp(line, "rb", 3))
		checker_rotate(stack_b, stack_a, 'a');
	else if (!ft_strncmp(line, "rr", 3))
		checker_rotate(stack_a, stack_b, 'r');
	else if (!ft_strncmp(line, "rra", 4))
		checker_rotate(stack_a, stack_b, 'A');
	else if (!ft_strncmp(line, "rrb", 4))
		checker_rotate(stack_b, stack_a, 'A');
	else if (!ft_strncmp(line, "rrr", 4))
		checker_rotate(stack_a, stack_b, 'R');
	else
		return (checker_command_2(line, data, stack_a, stack_b));
	return (0);
}

int	get_commands(t_data *data)
{
	char	*line;
	int		check;

	check = get_next_line(0, &line);
	while (check > 0)
	{
		if (checker_command(line, data, data->stack_a, data->stack_b) == -1)
		{
			free(line);
			clear_stack(data->stack_a);
			clear_stack(data->stack_b);
			return (-1);
		}
		free(line);
		line = NULL;
		check = get_next_line(0, &line);
	}
	if (line != NULL)
		free(line);
	line = NULL;
	if (checker_sorted(data->stack_a, data->stack_b) != -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (check);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_stack		a_stack;
	t_stack		b_stack;

	if (argc < 2)
		return (0);
	if (all_ints(argv, argc) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_structures(&data, &a_stack, &b_stack);
	fill_stack(argv, argc, &a_stack);
	if (no_doubles(&a_stack) == -1)
	{
		clear_stack(&a_stack);
		write(1, "Error\n", 6);
		return (0);
	}
	if (get_commands(&data) == -1)
		return (-1);
	clear_stack(&a_stack);
	clear_stack(&b_stack);
	return (0);
}
