/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:59:58 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 14:36:38 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	is_philo_full(t_ph *ph)
{
	lock(ph);
	if (ph->times_eaten == ph->table->meals)
		ph->table->philos_full++;
	unlock(ph);
}

static int	grap_forks(t_ph *ph)
{
	if (should_stop(ph))
		return (FAIL);
	lock_left_fork(ph);
	print_time_and_action(ph, "picks up a fork");
	lock_right_fork(ph);
	print_time_and_action(ph, "picks up a fork");
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
	ph->times_eaten++;
	is_philo_full(ph);
	unlock_forks(ph);
	return (true);
}
