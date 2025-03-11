/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:40:43 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 10:21:52 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	clean_and_free(t_table *table, int threads)
{
	int	i;

	i = -1;
	while (++i < threads)
		pthread_join(table->philos[i].thread, NULL);
	i = -1;
	while (++i < table->num_philos)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->lock);
	free(table->philos);
	free(table->forks);
}
