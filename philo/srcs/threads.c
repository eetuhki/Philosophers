/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:19:05 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/25 12:54:34 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static bool	philo_sleeps(t_ph *ph)
{
	if (should_stop(ph))
		return (false);
	print_time_and_action(ph, "is sleeping", 1);
	if (philo_waits(ph, ph->table->slp_t))
		return (false);
	return (true);
}

static int	thread_fail(t_table *table, int threads)
{
	clean_and_free(table, threads);
	perror("Error: Thread creation failed");
	return (FAIL);
}

static void	*single_philo(t_ph *ph)
{
	size_t	time;

	lock_lf(ph);
	time = ph->table->start_time;
	printf("%zu %d has taken a fork\n", (gettime() - time), 1);
	philo_waits(&ph->table->philos[0], ph->table->die_t);
	unlock_lf(ph);
	return (ph);
}

static void	*start_routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	lock(ph);
	while (!ph->table->start)
		usleep(1);
	unlock(ph);
	while (1)
	{
		if (ph->table->num_philos == 1)
			return (single_philo(ph));
		philo_is_thinking(ph, 1);
		if (ph->id % 2 == 0)
			philo_waits(ph, 10);
		if (philo_eats(ph) == false)
			break ;
		if (philo_sleeps(ph) == false)
			break ;
		if (!should_stop(ph))
		{
			philo_is_thinking(ph, 0);
			usleep(100);
		}
		else
			break ;
	}
	return (ph);
}

int	create_threads(t_table *table)
{
	int	i;

	lock_table(table);
	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &start_routine,
				(void *)&table->philos[i]) != SUCCESS)
			return (thread_fail(table, i));
	}
	table->start = 1;
	table->start_time = gettime();
	unlock_table(table);
	return (SUCCESS);
}
