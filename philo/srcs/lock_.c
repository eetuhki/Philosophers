/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:10:22 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/18 15:28:19 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	lock(t_ph *ph)
{
	pthread_mutex_lock(&ph->table->lock);
}

void	lock_table(t_table *table)
{
	pthread_mutex_lock(&table->lock);
}

void	lock_lf(t_ph *ph)
{
	pthread_mutex_lock(ph->l_fork);
}

void	lock_rf(t_ph *ph)
{
	pthread_mutex_lock(ph->r_fork);
}
