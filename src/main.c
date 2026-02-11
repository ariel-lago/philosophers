/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:46:30 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/11 20:38:46 by ariellago        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_context *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->philos);
	pthread_mutex_destroy(&table->philo_died_mutex);
	free(table->forks);
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
	if (init_context(&table, argv) == ERROR)
		return (write(2, "Error: malloc failed\n", 21), 1);
	init_philos(&table);
	if (init_threads(&table) == ERROR)
		return (write(2, "Error: failed to create thread\n", 31), 1);
	free_and_destroy(&table);
	return (0);
}
