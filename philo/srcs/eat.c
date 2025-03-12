/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:59:58 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/12 15:21:03 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	is_philo_full(t_ph *ph)
{
	lock(ph);
	if (((ph->times_eaten == ph->table->meals) || !ph->table->meals) && ph->table->meals != -1)
	{
		ph->table->philos_full++;
		if (ph->table->philos_full == ph->table->num_philos)
		{
			printf("\n\nALL PHILOS FULL\n\n");
			ph->table->stop = true;
		}
	}
	unlock(ph);
}

static int	grap_forks(t_ph *ph)
{
	if (should_stop(ph))
		return (FAIL);
	if (ph->id % 2 == 0 && !ph->table->stop)
	{
		lock_right_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		unlock_right_fork(ph);
		lock_left_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		unlock_left_fork(ph);
	}
	else if (!ph->table->stop)
	{
		lock_left_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		unlock_left_fork(ph);
		lock_right_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		unlock_right_fork(ph);
	}	
	if (should_stop(ph))
		return (unlock_forks(ph));
	return (SUCCESS);
}

bool	philo_eats(t_ph *ph)
{
	if (should_stop(ph))
		return (false);
	if (grap_forks(ph))
		return (false);
	print_time_and_action(ph, "is eating");
	lock(ph);
	ph->last_eat = gettime() - ph->table->start_time;
	unlock(ph);
	if (philo_waits(ph, ph->table->eat_t))
		return (unlock_forks(ph));
	lock(ph);
	ph->times_eaten++;
	unlock(ph);
	unlock_forks(ph);
	is_philo_full(ph);
	return (true);
}
