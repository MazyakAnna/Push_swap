/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack, t_elem *elem)
{
	if (stack == NULL)
		write(1, "ERROR!\nSTACK_PUSH: &stack == NULL!\n", 35);
	if (stack->top == NULL)
	{
		stack->root = elem;
		stack->top = elem;
		stack->size = 1;
	}
	else
	{
		elem->prev = stack->top;
		stack->top->next = elem;
		stack->top = elem;
		stack->size++;
	}
}

t_elem	*stack_pop(t_stack *stack)
{
	t_elem	*tmp;

	if (stack == NULL)
	{
		write(1, "ERROR!\nSTACK_POP: &stack == NULL!\n", 34);
		return (NULL);
	}
	if (stack->top == NULL)
	{
		write(1, "ERROR!\nSTACK_POP: stack->top == NULL!\n", 38);
		return (NULL);
	}
	tmp = stack->top;
	stack->top = tmp->prev;
	if (stack->top != NULL)
		stack->top->next = NULL;
	else
		stack->root = NULL;
	stack->size--;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/*
** works only on not broken stacks!
*/
void	stack_topswap(t_stack *stack)
{
	t_elem	*tmp;

	if (stack->size == 2)
		rotate_stack(stack);
	else if (stack->size > 2)
	{
		tmp = stack->top->prev;
		stack->top->next = tmp;
		tmp->prev->next = stack->top;
		stack->top->prev = tmp->prev;
		tmp->prev = stack->top;
		stack->top = tmp;
		tmp->next = NULL;
	}
}

/*
** 2 ops: create links between current root & top;
** 2 ops: top to root and new top;
** 2 ops: to NULL links for new root & top; 
*/
void	rotate_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->top != NULL && stack->root != NULL)
		{
			stack->top->next = stack->root;
			stack->root->prev = stack->top;
			stack->root = stack->top;
			stack->top = stack->top->prev;
			stack->root->prev = NULL;
			stack->top->next = NULL;
		}
	}
}

void	r_rotate_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->top != NULL && stack->root != NULL)
		{
			stack->root->prev = stack->top;
			stack->top->next = stack->root;
			stack->top = stack->root;
			stack->root = stack->root->next;
			stack->root->prev = NULL;
			stack->top->next = NULL;
		}
	}
}
