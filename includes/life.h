/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:25:28 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/06 17:53:51 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include "defines.h"

void  *did_philo_die(void *context);
int   check_and_print(t_philo *philo, char *str);
void	*life(void *philo);

#endif
