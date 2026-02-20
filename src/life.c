/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:42:40 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/20 23:05:57 by ariellago        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*did_philo_die(void *context)
{
	int			i;
	t_context	*table;
	long		meal_temp;
	int			had_enough;

	table = (t_context *)context;
	while (1)
	{
		i = 0;
		had_enough = 0;
		while (i < table->n_philo)
		{
			pthread_mutex_lock(&table->philos[i].meal_mutex);
			meal_temp = table->philos[i].last_meal;
			if(table->n_eat != -1 && table->n_eat <= table->philos[i].meal_num)
				had_enough++;
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
			if ((get_time_ms() - meal_temp) >= table->time_to_die)
			{
				check_and_print(&table->philos[i], "has died");
				pthread_mutex_lock(&table->write_mutex);
				table->philo_died = TRUE;
				pthread_mutex_unlock(&table->write_mutex);
				return (NULL);
			}
			i++;
		}
		if (table->n_philo == had_enough)
		{
			pthread_mutex_lock(&table->write_mutex);
			table->philo_died = TRUE;
			pthread_mutex_unlock(&table->write_mutex);
			return (NULL);	
		}
		usleep(1000);
	}
}

int	check_and_print(t_philo *philo, char *str)
{
	long	print_time;
	
	pthread_mutex_lock(&philo->table->write_mutex);
	if (philo->table->philo_died)
	{
		pthread_mutex_unlock(&philo->table->write_mutex);
		return (ERROR);
	}
	print_time = get_time_ms() - philo->table->start_time;
	printf("%ld %d %s\n", print_time, philo->n, str);
	pthread_mutex_unlock(&philo->table->write_mutex);
	return (0);
}

void	*life(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->n % 2 == 0)
		ft_usleep(philos->table->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&philos->meal_mutex);
		if(philos->table->n_eat != -1 && philos->table->n_eat <= philos->meal_num)
		{
			pthread_mutex_unlock(&philos->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philos->meal_mutex);
		if (check_and_print(philos, "is thinking") == ERROR)
			break ;
		pthread_mutex_lock(philos->left);
		if (check_and_print(philos, "has taken a fork") == ERROR)
		{
			pthread_mutex_unlock(philos->left);
			break;
		}
		if (philos->table->n_philo == 1)
		{
			ft_usleep(philos->table->time_to_die);
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
		pthread_mutex_lock(&philos->meal_mutex);
		philos->last_meal = get_time_ms();
		philos->meal_num++;
		pthread_mutex_unlock(&philos->meal_mutex);
		if (check_and_print(philos, "is eating") == ERROR)
		{
			pthread_mutex_unlock(philos->left);
			pthread_mutex_unlock(philos->right);
			break;
		}
		ft_usleep(philos->table->time_to_eat);
		pthread_mutex_unlock(philos->left);
		pthread_mutex_unlock(philos->right);
		if (check_and_print(philos, "is sleeping") == ERROR)
			break ;
		ft_usleep(philos->table->time_to_sleep);
	}
	return (NULL);
}
