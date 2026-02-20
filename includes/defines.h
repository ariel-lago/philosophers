/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariellago <ariellago@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:47:28 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/20 20:12:25 by ariellago        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct s_context	t_context;
typedef struct s_philo		t_philo;

typedef struct s_context {
	int				n_philo;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	long			start_time;
	int				philo_died;
	pthread_mutex_t	write_mutex;
}	t_context;

typedef struct s_philo {
	int					n;
	int					meal_num;
	long				last_meal;
	pthread_mutex_t		meal_mutex;
	pthread_t			thread_id;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	t_context			*table;
}	t_philo;

#endif
