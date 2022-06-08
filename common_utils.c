/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaegan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:38:17 by bmaegan           #+#    #+#             */
/*   Updated: 2021/08/20 14:38:37 by bmaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '\x30' && c <= '\x39')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

long	ft_atol(const char *s)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

int	all_ints(char **line, int arg_num)
{
	int		i;
	int		j;
	long	check;

	i = 1;
	while (i < arg_num)
	{
		j = 0;
		if (line[i][j] == '-')
			j++;
		while (line[i][j] != '\0')
		{
			if (ft_isdigit(line[i][j]) != 0 && j < 12)
				j++;
			else
				return (-1);
		}
		check = ft_atol(line[i]);
		if (check > 2147483647 || check < -2147483648)
			return (-1);
		i++;
	}
	return (1);
}

/*
** returns (1) if there is ascii digit in strnum
** and (0) if there's no occurances
*/
int	digit_in_str(int digit, char *strnum)
{
	while (*strnum != '\0')
	{
		if (digit == *strnum - '0')
			return (1);
		else
			strnum++;
	}
	return (0);
}
