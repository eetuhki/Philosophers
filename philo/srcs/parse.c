/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:42:28 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/13 15:30:30 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static bool	only_digits(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	return (true);
}

static char	*trim_whitespace(char *s)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	return (s);
}

static int	atoi_ph(char *s)
{
	long int	res;

	res = 0;
	if (*s == 0)
		return (ERROR);
	s = trim_whitespace(s);
	if (!only_digits(s))
		return (ERROR);
	if (*s == '-')
		return (ERROR);
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s++ - '0';
		if (res > INT_MAX)
			return (ERROR);
	}
	return ((int)res);
}

static int	store_args(t_table *table, int ac, char **av)
{
	table->num_philos = atoi_ph(av[1]);
	if (table->num_philos < 1 || table->num_philos > 1000)
		return (FAIL);
	table->die_t = atoi_ph(av[2]);
	if (!table->die_t)
		return (FAIL);
	table->eat_t = atoi_ph(av[3]);
	if (!table->eat_t)
		return (FAIL);
	table->slp_t = atoi_ph(av[4]);
	if (!table->slp_t)
		return (FAIL);
	table->meals = -1;
	if (ac == 6)
		table->meals = atoi_ph(av[5]);
	if (!table->meals)
		return (FAIL);
	return (SUCCESS);
}

int	check_av(t_table *table, int ac, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (atoi_ph(av[i]) == ERROR)
			return (FAIL);
	}
	if (store_args(table, ac, av))
		return (FAIL);
	return (SUCCESS);
}
