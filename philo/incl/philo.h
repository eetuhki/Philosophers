/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:49:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/04 15:24:03 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAIL 1
# define ERROR -1

typedef struct s_ph
{
	t_table			*table;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	size_t			last_eat;
	int				times_eaten;
	int				id;
	pthread_t		t;	
}	t_ph;

typedef struct s_table
{
	t_ph	*philos;
	int		num_philos;
	int		philos_full;
	int		meals;
	int		start;
	int		stop;
	size_t	die_t;
	size_t	eat_t;
	size_t	slp_t;
}	t_table;

int		guide();
int		check_av(t_table *table, char **av);

#endif