/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:39:49 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:39:57 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*create_elem(int data)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (new != NULL)
	{
		new->val = data;
		new->index = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_elem	*add_elem(t_elem *prev_el, int data)
{
	t_elem	*new;

	if (prev_el == NULL)
	{
		write(1, "ERROR!\nADD_ELEM: prev_el == NULL\n", 33);
		return (NULL);
	}
	new = (t_elem *)malloc(sizeof(t_elem));
	if (new != NULL)
	{
		new->val = data;
		new->next = prev_el->next;
		new->prev = prev_el;
		prev_el->next = new;
		if (new->next != NULL)
			new->next->prev = new;
	}
	return (new);
}

t_elem	*del_elem(t_elem *elem)
{
	t_elem	*next_el;
	t_elem	*prev_el;

	next_el = elem->next;
	prev_el = elem->prev;
	if (next_el != NULL)
		next_el->prev = prev_el;
	if (prev_el != NULL)
		prev_el->next = next_el;
	free(elem);
	return (prev_el);
}
