/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:46:30 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/02 20:25:42 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_context(t_context table)
{
	table->n_philo = (int)ft_atopl(argv[1]);
	table->time_to_die = (int)ft_atopl(argv[2]);
	table->time_to_eat = (int)ft_atopl(argv[3]);
	table->time_to_sleep = (int)ft_atopl(argv[4]);
	if (argv[5])
		table->n_eat = (int)ft_atopl(argv[5]);
	else
		table->n_eat = -1;
	table->philo_died = 0;
	table->philo_list = init_philo_list;
	if (!table->philo_list)
		return (ERROR);
	return (0);
}

int	init_philo_list(int n, t_context table)
{
}

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
	if (init_context(table, char *argv[]) == ERROR)
		return (write(2, "Error: malloc failed\n", 21), 1); 
}
