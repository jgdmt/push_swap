/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:07:29 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/28 12:51:31 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int to_free, char **strs)
{
	if (to_free == 1)
		ft_free_arg(strs);
	write(2, "Error\n", 6);
	exit (-1);
}

void	ft_check_format(char *str, char **strs, int to_free, t_stack **a)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	if (str[i] == '-')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0')
	{
		ft_free_stack(a);
		ft_error(to_free, strs);
	}
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] != 0 || i > 11)
	{
		ft_free_stack(a);
		ft_error(to_free, strs);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '-' && s1[1] == '0' && s2[0] == '0')
		return (0);
	if (s2[0] == '-' && s2[1] == '0' && s1[0] == '0')
		return (0);
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_check_double(int num, char **strs, int to_free)
{
	int	i;
	int	j;

	i = 1;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (i != j)
				if (ft_strcmp(strs[i], strs[j]) == 0)
					ft_error(to_free, strs);
			j++;
		}
		i++;
	}
}
