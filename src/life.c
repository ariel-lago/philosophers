/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:42:40 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/11 23:56:38 by ariellago        ###   ########.fr       */
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
				check_and_print(table->philos, "has died");
				pthread_mutex_lock(&table->philo_died_mutex);
				table->philo_died = TRUE;
				pthread_mutex_unlock(&table->philo_died_mutex);
				return (NULL);
			}
			i++;
		}
	}
}

int	check_and_print(t_philo *philo, char *str)
{
	long	print_time;
	
	pthread_mutex_lock(&philo->table->philo_died_mutex);
	if (philo->table->philo_died)
	{
		pthread_mutex_unlock(&philo->table->philo_died_mutex);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->table->philo_died_mutex);
	print_time = get_time_ms() - philo->table->start_time;
	printf("%ld %d %s\n", print_time, philo->n, str);
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
		if (check_and_print(philos, "is thinking") == ERROR)
			break ;
		pthread_mutex_lock(philos->left);
		if (check_and_print(philos, "has taken a fork") == ERROR)
		{
			pthread_mutex_unlock(philos->left);
			break;
		}
		pthread_mutex_lock(philos->right);
		if (check_and_print(philos, "has taken a fork") == ERROR)
		{
			pthread_mutex_unlock(philos->left);
			pthread_mutex_unlock(philos->right);
			break;
		}
		philos->last_meal = get_time_ms();
		philos->meal_num++;
		if (check_and_print(philos, "is eating") == ERROR)
		{
			pthread_mutex_unlock(philos->left);
			pthread_mutex_unlock(philos->right);
			break;
		}
		usleep(philos->table->time_to_eat * 1000);
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		if (check_and_print(philos, "is sleeping") == ERROR)
			break ;
		usleep(philos->table->time_to_sleep * 1000);
	}
	return (NULL);
}
