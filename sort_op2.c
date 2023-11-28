/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:21:57 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/14 13:22:01 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(t_stack **s)
{
	int		value;
	t_stack	*curr;

	curr = *s;
	value = curr->value;
	while ((*s)->value != curr->next->value)
	{
		curr = curr->next;
		if (curr->value > value)
			value = curr->value;
	}
	return (value);
}

int	ft_get_min(t_stack **s)
{
	int		value;
	t_stack	*curr;

	curr = *s;
	value = curr->value;
	while ((*s)->value != curr->next->value)
	{
		curr = curr->next;
		if (curr->value < value)
			value = curr->value;
	}
	return (value);
}

int	ft_find_prev(t_stack **s, t_stack *elem)
{
	t_stack	*curr;
	int		idx;
	int		i;

	curr = *s;
	idx = elem->idx - 1;
	if (elem->idx == 1)
		return (ft_get_max(s));
	while (idx > 0)
	{
		i = ft_slen(s);
		while (i > 0)
		{
			if (curr->idx == idx)
				return (curr->value);
			curr = curr->next;
			i--;
		}
		idx--;
	}
	return (ft_get_max(s));
}

int	ft_find_next(t_stack **s, t_stack *elem, int max)
{
	t_stack	*curr;
	int		idx;
	int		i;

	curr = *s;
	idx = elem->idx + 1;
	if (elem->idx == max)
		return (ft_get_min(s));
	while (idx <= max)
	{
		i = ft_slen(s);
		while (i > 0)
		{
			if (curr->idx == idx)
				return (curr->value);
			curr = curr->next;
			i--;
		}
		idx++;
	}
	return (ft_get_min(s));
}
