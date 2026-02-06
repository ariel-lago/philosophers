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

void	*life(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	printf("soy el filo numero: %i\n", philos->n);
	while (!philos->table.philo_died)
	{
		if (philos->table.philo_died)
			break ;
		printf("%ld %i is thinking\n", get_time_ms(), philos->n);
		if (philos->n % 2)
			usleep(300);
		pthread_mutex_lock(philos->left);
		if (philos->table.philo_died)
			break ;
		printf("%ld %i has taken a fork\n", get_time_ms(), philos->n);
		pthread_mutex_lock(philos->right);
		philos->last_meal = get_time_ms();
		if (philos->table.philo_died)
			break ;
		printf("%ld %i is eating\n", get_time_ms(), philos->n);
		usleep(philos->table.time_to_eat);
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		if (philos->table.philo_died)
			break ;
		printf("%ld %i is sleeping\n", get_time_ms(), philos->n);
		usleep(philos->table.time_to_sleep);
	}
	return (NULL);
}
