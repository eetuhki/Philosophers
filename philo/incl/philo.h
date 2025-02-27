/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:49:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/02/28 00:10:36 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define FAIL 1
# define ERROR -1

typedef struct s_ph
{
	int		phils;
	int		meals;
	size_t	die_t;
	size_t	eat_t;
	size_t	slp_t;
}	t_ph;

int		err_phils();
int		err_range();
int		err_usage();
int		invalid_ac(int ac);
int		parse(t_ph *ph, char **av);

#endif