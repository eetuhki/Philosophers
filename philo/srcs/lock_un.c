/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_un.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:17:32 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/11 20:59:32 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	unlock(t_ph *ph)
{
	pthread_mutex_unlock(&ph->table->lock);
}

void	unlock_table(t_table *table)
{
	pthread_mutex_unlock(&table->lock);
}

void	unlock_left_fork(t_ph *ph)
{
	pthread_mutex_unlock(ph->l_fork);
}

void	unlock_right_fork(t_ph *ph)
{
	pthread_mutex_unlock(ph->r_fork);
}

bool	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
	return (true);
}
