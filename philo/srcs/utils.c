/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:13:10 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 15:36:56 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	print_time_and_action(t_ph *ph, char *action, int protect)
{
	size_t	time;

	if (protect)
		usleep(1);
	lock(ph);
	if (ph->table->stop && protect)
	{
		unlock(ph);
		return ;
	}
	time = gettime() - ph->table->start_time;
	printf("%zu %d %s\n", time, ph->id, action);
	unlock(ph);
}

size_t	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	should_stop(t_ph *ph)
{
	lock(ph);
	if (ph->table->stop || ph->table->philos_full == ph->table->num_philos)
	{
		unlock(ph);
		return (true);
	}
	unlock(ph);
	return (false);
}

int	philo_waits(t_ph *ph, size_t ms)
{
	size_t	tmp;

	tmp = gettime();
	while (((gettime() - tmp) < ms))
	{
		usleep(100);
		if (should_stop(ph))
			return (FAIL);
	}
	return (SUCCESS);
}

void	philo_is_thinking(t_ph *ph, int validate)
{
	if (validate && !(ph->id % 2))
	{
		if (ph->table->init)
		{
			print_time_and_action(ph, "is thinking", 1);
			philo_waits(ph, ph->table->eat_t);
			ph->table->init = 0;
		}
	}
	if (validate && (ph->table->num_philos % 2)
		&& ph->id == ph->table->num_philos)
	{
		if (ph->table->init)
		{
			print_time_and_action(ph, "is thinking", 1);
			philo_waits(ph, ph->table->eat_t);
			ph->table->init = 0;
		}
	}
	if (!validate)
	{
		print_time_and_action(ph, "is thinking", 1);
		if (ph->table->slp_t < ph->table->eat_t)
			philo_waits(ph, ph->table->eat_t - ph->table->slp_t);
	}
}
