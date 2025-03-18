/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:14:46 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/18 15:58:06 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static bool	philo_dies(t_ph *ph)
{
	size_t	time;

	lock(ph);
	if (!ph->table->stop)
	{
		time = gettime() - ph->table->start_time;
		if (time - ph->last_eat > ph->table->die_t)
		{
			ph->table->stop = true;
			unlock(ph);
			print_time_and_action(ph, "died", 0);
			return (true);
		}
	}
	unlock(ph);
	return (false);
}

static bool	conditions_fulfilled(t_table *table)
{
	int	i;
	int	num_philos;
	int	philos_full;

	i = -1;
	while (++i < table->num_philos && !table->stop)
	{
		if (philo_dies(&table->philos[i]))
			return (true);
	}
	lock_table(table);
	num_philos = table->num_philos;
	philos_full = table->philos_full;
	unlock_table(table);
	if (table->meals != -1 && philos_full == num_philos)
	{
		lock_table(table);
		table->stop = true;
		unlock_table(table);
		return (true);
	}
	return (false);
}

void	monitor(t_table *table)
{
	while (1)
	{
		if (conditions_fulfilled(table) == true)
			break ;
	}
	clean_and_free(table, table->num_philos);
}
