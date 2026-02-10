/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:42:40 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/06 21:22:40 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*did_philo_die(void *context)
{
	int	i;
	t_context	*table;

	table = (t_context *)context;
	while (1)
	{
		i = 0;
		while (i < table->n_philo)
		{
			if (get_time_ms() - table->time_to_die > table->philos[i].last_meal)
			{
				table->philo_died = TRUE;
				printf("%ld %i has died/n", get_time_ms(), table->philos[i].n);
				return (NULL);
			}
			i++;
		}
	}
}

int	check_and_print(t_philo *philo, char *str)
{
	long	print_time;
	
	if (philo->table->philo_died)
		return (ERROR);
	print_time = get_time_ms() - philo->table->start_time;
	printf("%ld %d %s/n", print_time, philo->n, str);
	return (0);
}

void	*life(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->n % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philos->table->philo_died)
			break ;
		if (check_and_print(philos, "is thinking") == ERROR)
			break ;
		pthread_mutex_lock(philos->left);
		if (check_and_print(philos, "has taken a fork") == ERROR)
			break ;
		pthread_mutex_lock(philos->right);
		if (check_and_print(philos, "has taken a fork") == ERROR)
			break ;
		philos->last_meal = get_time_ms();
		if (check_and_print(philos, "is eating") == ERROR)
			break ;
		usleep(philos->table->time_to_eat);
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		if (check_and_print(philos, "is sleeping") == ERROR)
			break ;
		usleep(philos->table->time_to_sleep);
	}
	return (NULL);
}
