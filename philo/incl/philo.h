/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:49:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 14:31:28 by eelaine          ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef struct s_ph
{
	int				times_eaten;
	int				id;
	t_table			*table;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	size_t			last_eat;
	pthread_t		thread;	
}	t_ph;

typedef struct s_table
{
	t_ph			*philos;
	int				num_philos;
	int				philos_full;
	int				meals;
	bool			start;
	bool			stop;
	size_t			die_t;
	size_t			eat_t;
	size_t			slp_t;
	size_t			start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;
}	t_table;

//arg validation
int		check_av(t_table *table, char **av);

//clean
void	clean_and_free(t_table *table, int threads);

//error
int		fork_mutex_fail(t_table *table);
int		forks_malloc_fail(t_table *table);
int		guide(void);
int		init_mutex_fail(t_table *table);
int		philos_array_fail(void);
int		thread_fail(t_table *table, int threads);

//initialization
int		init(t_table *table);

//lock and unlock
void	lock(t_ph *ph);
void	lock_table(t_table *table);
void	lock_left_fork(t_ph *ph);
void	lock_right_fork(t_ph *ph);
void	unlock(t_ph *ph);
void	unlock_table(t_table *table);
void	unlock_left_fork(t_ph *ph);
void	unlock_right_fork(t_ph *ph);
bool	unlock_forks(t_ph *ph);

//monitor
void	monitor(t_table *table);

//philosopher actions
bool	philo_eats(t_ph *ph);
bool	philo_sleeps(t_ph *ph);
int		philo_waits(t_ph *ph, size_t ms);
void	philo_is_thinking(t_ph *ph, int validate);

//start simulation
int		create_threads(t_table *table);

//utils
size_t	gettime(void);
void	print_time_and_action(t_ph *ph, char *action);
bool	should_stop(t_ph *ph);

#endif