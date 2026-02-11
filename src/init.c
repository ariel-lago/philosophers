/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:11:57 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/11 23:50:00 by ariellago        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_context(t_context *table, char **argv)
{
	int	i;

	i = 0;
	table->n_philo = (int)ft_atopi(argv[1]);
	table->time_to_die = (int)ft_atopi(argv[2]);
	table->time_to_eat = (int)ft_atopi(argv[3]);
	table->time_to_sleep = (int)ft_atopi(argv[4]);
	if (argv[5])
		table->n_eat = (int)ft_atopi(argv[5]);
	else
		table->n_eat = -1;
	table->philo_died = FALSE;
	if (pthread_mutex_init(&table->philo_died_mutex, NULL) != 0)
		return (ERROR);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
		return (ERROR);
	while (i < table->n_philo)
		if (pthread_mutex_init(&table->forks[i++], NULL) != 0)
			return (free(table->forks), ERROR);
	table->philos = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philos)
		return (free(table->forks), ERROR);
	return (0);
}

void	init_philos(t_context *table)
{
	int		i;

	i = 0;
	while (i < table->n_philo)
	{
		table->philos[i].n = i + 1;
		table->philos[i].meal_num = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].left = &table->forks[i];
		table->philos[i].right = &table->forks[(i + 1) % table->n_philo];
		table->philos[i].table = table;
		i++;
	}
}

int	init_threads(t_context *table)
{
	int	i;
	pthread_t	death_thread;

	table->start_time = get_time_ms();
	i = 0;
	while (i < table->n_philo)
	{
		table->philos[i].last_meal = get_time_ms();
		if (pthread_create(&table->philos[i].thread_id,
				NULL, &life, &table->philos[i]) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_create(&death_thread, NULL, &did_philo_die, table) != 0)
		return (ERROR);
	i = 0;
	while (i < table->n_philo)
		pthread_join(table->philos[i++].thread_id, NULL);
	pthread_join(death_thread, NULL);
	return (0);
}
