/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:29 by eelaine           #+#    #+#             */
/*   Updated: 2025/02/27 23:12:21 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"
#include <stdbool.h>

int	invalid_ac(int ac)
{
	if (ac < 5 || ac > 6)
		return (err_usage());
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_ph	ph;

	memset(&ph, 0, sizeof(t_ph));
	if (invalid_ac(ac))
		return (FAIL);
	if (parse(&ph, av))
		return (FAIL);
	return (SUCCESS);
}
