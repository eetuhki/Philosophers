/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:29 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 15:23:36 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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
	if (check_ac(ac) == FAIL)
		return (guide());
	if (check_av(&table, ac, av) == FAIL)
		return (guide());
	if (init(&table) == FAIL)
		return (FAIL);
	if (create_threads(&table) == FAIL)
		return (FAIL);
	monitor(&table);
	return (SUCCESS);
}
