/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:08:18 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/29 12:42:40 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_stnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	new->value = value;
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

void	ft_init_stack(int value, t_stack **a, int to_free, char **argv)
{
	t_stack	*new;

	new = ft_stnew(value);
	if (!new)
	{
		ft_free_stack(a);
		if (to_free)
			ft_free_arg(argv);
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
