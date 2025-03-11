/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:00:41 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 14:27:53 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	fork_mutex_fail(t_table *table)
{
	perror("Error: Fork mutex initalization failed");
	pthread_mutex_destroy(&table->lock);
	free(table->forks);
	return (FAIL);
}

int	forks_malloc_fail(t_table *table)
{
	perror("Error: Memory allocation for the forks failed");
	pthread_mutex_destroy(&table->lock);
	return (FAIL);
}

int	init_mutex_fail(t_table *table)
{
	free(table->philos);
	perror("Error: Initialization failed: Mutex array");
	return (FAIL);
}

int	philos_array_fail(void)
{
	perror("Error: Memory allocation failed: Philosophers' array");
	return (FAIL);
}

int	guide(void)
{
	printf("\n	Please launch ./philo with:\n\n");
	printf("	1. the number of philosophers\n");
	printf("	2. the time when a philosopher should die\n");
	printf("	3. the time it takes for a philosopher to eat\n");
	printf("	4. the time a philosopher will spend sleeping\n\n");
	printf("	(optional)\n");
	printf("	5. the number of times each philosopher eats\n\n");
	printf("	valid arguments:\n");
	printf("	- the number of philosophers 1 - 200\n");
	printf("	- the duration of any action >= 1\n");
	printf("	- the number of meals can be >= 0\n");
	printf("	- please use positive integers <= INT_MAX\n\n");
	return (ERROR);
}
