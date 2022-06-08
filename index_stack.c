/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:38:17 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:38:37 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

void	arr_qsort(int *arr, int size)
{
	int	tmp;
	int	mid;
	int	i;
	int	j;

	j = size - 1;
	i = 0;
	mid = arr[j / 2];
	while (i < j)
	{
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (arr[i] > arr[j])
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	if (i > 0 && arr_sorted(arr, i) == -1)
		arr_qsort(arr, i);
	if (i < (size - 1) && arr_sorted(&arr[i], size - i) == -1)
		arr_qsort(&arr[i], size - i);
}

void	indx_to_stack(t_stack *stack, int *arr)
{
	t_elem	*tmp;
	int		i;

	tmp = stack->root;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->val != arr[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
}

int	index_stack(t_stack *stack)
{
	int		*arr;
	int		i;
	t_elem	*tmp;

	if (stack == NULL)
		return (-1);
	arr = (int *)malloc(sizeof(int) * stack->size);
	i = 0;
	tmp = stack->root;
	while (tmp != NULL)
	{
		arr[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	if (arr_sorted(arr, i) == -1)
		arr_qsort(arr, i);
	indx_to_stack(stack, arr);
	free(arr);
	return (1);
}
