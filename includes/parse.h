/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:27:30 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/02 19:29:54 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "defines.h"

int	is_space_or_plus(char c);
int	is_digit(char c);
int	is_valid_input(const char *str);
int	ft_atopi(const char *str);

#endif
