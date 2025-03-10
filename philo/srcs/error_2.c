/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:33:24 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/10 21:46:06 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	thread_fail(t_table *table, int threads)
{
	int	i;

	i = -1;
	while (i < threads)
		pthread_join(table->philos[i].thread, NULL);
	clean_and_free(table);
	perror("Error: Thread creation failed");
	return (FAIL);
}
