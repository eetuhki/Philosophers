/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:28:11 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 14:30:49 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	init_philo(t_table *table, t_ph *ph, int i)
{
	ph->l_fork = &table->forks[i];
	ph->r_fork = &table->forks[(i + 1) % table->num_philos];
	ph->id = i + 1;
	ph->times_eaten = 0;
	ph->last_eat = 0;
	ph->table = table;
}

static int	init_arrays(t_table *table)
{
	int	i;

	if (pthread_mutex_init(&table->lock, NULL) != SUCCESS)
		return (FAIL);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (forks_malloc_fail(table));
	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != SUCCESS)
		{
			while (i > 0)
				pthread_mutex_destroy(&table->forks[--i]);
			return (fork_mutex_fail(table));
		}
		init_philo(table, &table->philos[i], i);
	}
	return (SUCCESS);
}

int	init(t_table *table)
{
	table->start = false;
	table->stop = false;
	table->philos_full = 0;
	if (table->philos)
		free(table->philos);
	table->philos = malloc(table->num_philos * sizeof(t_ph));
	if (!table->philos)
		return (philos_array_fail());
	if (init_arrays(table) == FAIL)
		return (init_mutex_fail(table));
	return (SUCCESS);
}
