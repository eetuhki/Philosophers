/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:38:59 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/18 15:58:32 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

bool	philo_sleeps(t_ph *ph)
{
	if (should_stop(ph))
		return (false);
	print_time_and_action(ph, "is sleeping", 1);
	if (philo_waits(ph, ph->table->slp_t))
		return (false);
	return (true);
}
