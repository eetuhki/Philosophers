/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:29 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/04 15:12:19 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"
#include <stdbool.h>

static int	check_ac(int ac)
{
	if (ac < 5 || ac > 6)
		return (FAIL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (check_ac(ac))
		return (guide());
	if (check_av(&table, av))
		return (guide());
	if (init(&table))
		return (FAIL);
	return (SUCCESS);
}
