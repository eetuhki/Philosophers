/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:13:10 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 22:59:58 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	print_time_and_action(t_ph *ph, char *action)
{
	size_t	time;

	lock(ph);
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
	if (ph->table->stop)
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
	while ((gettime() - tmp) < ms)
	{
		usleep(500);
		if (should_stop(ph))
			return (FAIL);
	}
	return (SUCCESS);
}

void	philo_is_thinking(t_ph *ph, int validate)
{
	if (validate && !(ph->id % 2))
	{
		print_time_and_action(ph, "is thinking");
		philo_waits(ph, ph->table->eat_t / 2);
	}
	if (!validate)
	{
		print_time_and_action(ph, "is thinking");
	}
}
