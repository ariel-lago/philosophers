/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:46:30 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/03 19:13:52 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_context	table;
	int			i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (write(2, "Error: wrong number of arguments\n", 33), 1);
	while (i < argc)
	{
		if (!is_valid_input(argv[i]))
			return (write(2, "Error: expected positive integers\n", 34), 1);
		i++;
	}
	if (init_context(&table, *argv[]) == ERROR)
		return (write(2, "Error: malloc failed\n", 21), 1);
	if (init_philosophers(&table);
}
