/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:59:58 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 22:39:02 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	is_philo_full(t_ph *ph)
{
	lock(ph);
	printf("amount of meals: %d\n", ph->table->meals);
	if (ph->times_eaten == ph->table->meals && ph->table->meals != -1)
	{
		lock_table(ph->table);
		printf("amount of meals: %d\n", ph->table->meals);
		printf("%d is full after %d meals\n", ph->id, ph->times_eaten);
		ph->table->philos_full++;
		unlock_table(ph->table);
	}
	unlock(ph);
}

static int	grap_forks(t_ph *ph)
{
	if (should_stop(ph))
		return (FAIL);
	if (ph->id % 2 == 0)
	{
		lock_right_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		lock_left_fork(ph);
		print_time_and_action(ph, "has taken a fork");
	}
	else
	{
		lock_left_fork(ph);
		print_time_and_action(ph, "has taken a fork");
		lock_right_fork(ph);
		print_time_and_action(ph, "has taken a fork");
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
	ph->times_eaten++;
	printf("%d has eaten %d/%d times\n", ph->id, ph->times_eaten, ph->table->meals);
	is_philo_full(ph);
	unlock_forks(ph);
	return (true);
}
