/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:43:41 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/29 12:40:28 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	new->value = value;
	new->idx = 0;
	return (new);
}

void	ft_push(t_stack **a, t_stack *new)
{
	if (*a == 0)
		*a = new;
	else
	{
		new->next = *a;
		new->prev = (*a)->prev;
		(new->prev)->next = new;
		(*a)->prev = new;
		*a = new;
	}
}

void	ft_stack_idx(t_stack **s, int s_size)
{
	int		i;
	t_stack	*curr;
	t_stack	*temp;

	i = 1;
	if (*s == 0)
		return ;
	temp = *s;
	curr = *s;
	while (i <= s_size)
	{
		curr = curr->next;
		if (curr->value < temp->value && curr->idx == 0)
			temp = curr;
		if (curr->value == (*s)->value)
		{
			temp->idx = i++;
			while (temp->idx != 0 && i <= s_size)
				temp = temp->next;
		}
	}
}

void	ft_init_stack(int value, t_stack **a, int to_free, char **argv)
{
	t_stack	*new;

	new = ft_stnew(value);
	if (!new)
	{
		if (to_free)
			ft_free_arg(argv);
		ft_free_stack(a);
		exit(-1);
	}
	ft_push(a, new);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*curr;

	if (*a == 0)
		return ;
	curr = *a;
	curr->prev->next = 0;
	while (curr != 0)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}
