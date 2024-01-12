/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:43:34 by otodd             #+#    #+#             */
/*   Updated: 2023/10/20 10:39:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_valid_operator(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_invalid_char(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *c)
{
	int	value;
	int	operation;

	operation = 1;
	value = 0;
	while (ft_is_invalid_char(*c))
		c++;
	while (ft_is_valid_operator(*c))
	{
		if (*c == '-')
			operation *= -1;
		c++;
	}
	while (ft_is_numeric(*c))
	{
		value = (value * 10) + (*c - '0');
		c++;
	}
	return (value * operation);
}

int	main(void)
{
	printf("%d\n", ft_atoi("                  +++------+++++----++++++++++-------+--+1234ab567"));
	return (0);
}
