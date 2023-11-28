/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:07:33 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/27 17:48:51 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static long int	ft_atoli(char *str, t_stack **a, int to_free, char **argv)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = -1;
	if (str[++i] == '-')
		sign = -1;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
	{
		ft_free_stack(a);
		if (to_free == 1)
			ft_free_arg(argv);
		ft_error();
	}
	if (to_free == 1)
		free(str);
	return (num);
}

int	main(int argc, char *argv[])
{
	long int	num;
	t_stack		*a;
	t_stack		*b;
	int			is_mal;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	is_mal = 0;
	if (argc == 2)
		argv = ft_mod_split(argv, &argc, &is_mal);
	ft_check_double(argc, argv);
	while (--argc >= 1)
	{
		ft_check_format(argv[argc]);
		num = ft_atoli(argv[argc], &a, is_mal, argv);
		ft_init_stack(num, &a);
	}
	if (is_mal == 1)
		free(argv);
	ft_stack_idx(&a, ft_slen(&a));
	ft_sort(&a, &b);
	ft_free_stack(&a);
	return (0);
}
