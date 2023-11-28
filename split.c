/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:43:48 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/28 12:00:02 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordlen(char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == '-')
	{
		i++;
		count++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		i++;
		count++;
	}
	return (count);
}

static int	ft_count(char *str)
{
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (c > 0 && *str == '-' && (*(str - 1) != ' '))
			ft_error(0, 0);
		if (*str == '-' && (*(str + 1) <= '9' && *(str + 1) >= '0'))
			str++;
		if (*str == '0' && (*(str + 1) != ' ' && *(str + 1) != '\0'))
			ft_error(0, 0);
		if ((*str > '9' || *str < '0') && *str != '\0')
			ft_error(0, 0);
		if (*str >= '0' && *str <= '9')
			c++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (c == 0)
		ft_error(0, 0);
	return (c);
}

static int	ft_free(char **strs, int len)
{
	int	i;

	i = 1;
	while (i < len)
		free(strs[i++]);
	free(strs);
	return (-1);
}

static int	ft_make_words(char **strs, char *s, int w_num, int *argv)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	while (w_num < *argv)
	{
		while (s[i] == ' ')
			i++;
		word = malloc(ft_wordlen(s, i) + 1);
		if (!word)
			return (ft_free(strs, w_num));
		j = 0;
		if (s[i] == '-')
			word[j++] = s[i++];
		while (s[i] <= '9' && s[i] >= '0')
			word[j++] = s[i++];
		word[j] = 0;
		strs[w_num++] = word;
	}
	return (0);
}

char	**ft_mod_split(char **str, int *argv, int *is_mal)
{
	char	**strs;

	*argv = ft_count(str[1]) + 1;
	if (*argv == 2)
		return (str);
	strs = malloc(*argv * sizeof(char *));
	if (!strs)
		exit (-1);
	strs[0] = str[0];
	if (ft_make_words(strs, str[1], 1, argv) == -1)
	{
		*argv = 0;
		return (0);
	}
	*is_mal = 1;
	return (strs);
}
