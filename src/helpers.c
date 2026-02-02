/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:06:07 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/02 20:12:55 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atopl(const char	*str)
{
	long	result;

	result = 0;
	while (*str && is_space_or_plus(*str))
		str++;
	while (*str && is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result > 2147483647)
		return (ERROR);
	return (result);
}

int	is_space_or_plus(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13) || c == '+');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_input(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (FALSE);
	while (str[i])
	{
		if (!is_space_or_plus(str[i]) && !is_digit(str[i]))
			return (FALSE);
		i++;
	}
	if (ft_atopl(str) == ERROR)
		return (FALSE);
	return (TRUE);
}
