/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:07:00 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/27 17:40:07 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_slen(t_stack **s)
{
	t_stack	*curr;
	int		len;

	len = 1;
	if (*s == 0)
		return (0);
	curr = (*s)->next;
	while (curr->value != (*s)->value)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

int	ft_is_sorted(t_stack **a)
{
	t_stack	*curr;

	if (*a == 0)
		return (0);
	curr = (*a)->next;
	while ((*a)->value != curr->value)
	{
		if (curr->value < curr->prev->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
