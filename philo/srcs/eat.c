/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:59:58 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 15:38:46 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	is_philo_full(t_ph *ph)
{
	lock(ph);
	if (((ph->times_eaten == ph->table->meals)
			|| !ph->table->meals) && ph->table->meals != -1)
	{
		ph->table->philos_full++;
		if (ph->table->philos_full == ph->table->num_philos)
			ph->table->stop = true;
	}
	unlock(ph);
}

static int	take_forks(t_ph *ph)
{
	if (should_stop(ph))
		return (FAIL);
	if (!(ph->id % 2) && !ph->table->stop)
	{
		lock_rf(ph);
		print_time_and_action(ph, "has taken a fork", 1);
		lock_lf(ph);
		print_time_and_action(ph, "has taken a fork", 1);
	}
	else if (!ph->table->stop)
	{
		lock_lf(ph);
		print_time_and_action(ph, "has taken a fork", 1);
		lock_rf(ph);
		print_time_and_action(ph, "has taken a fork", 1);
	}
	if (should_stop(ph))
		return (unlock_forks(ph));
	return (SUCCESS);
}

bool	philo_eats(t_ph *ph)
{
	if (take_forks(ph) == FAIL)
		return (false);
	print_time_and_action(ph, "is eating", 1);
	lock(ph);
	ph->last_eat = gettime() - ph->table->start_time;
	ph->times_eaten++;
	unlock(ph);
	if (philo_waits(ph, ph->table->eat_t))
		return (unlock_forks(ph));
	unlock_forks(ph);
	is_philo_full(ph);
	return (true);
}
