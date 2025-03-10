/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:19:05 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/10 21:49:04 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	create_threads(t_table *table)
{
	int	i;

	pthread_mutex_lock(&table->lock);
	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
			(void *)&table->philos[i]) != SUCCESS)
			return (thread_fail(table, i));
	}
	
	return (SUCCESS);
}
