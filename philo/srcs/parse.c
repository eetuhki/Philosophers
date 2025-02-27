/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:42:28 by eelaine           #+#    #+#             */
/*   Updated: 2025/02/28 00:12:07 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

char	*trim_whitespace(char *s)
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
	if (*s == '-')
		return (err_range());
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s++ - '0';
		if (res > INT_MAX)
			return (err_range());
	}
	return ((int)res);
}

int	parse(t_ph *ph, char **av)
{
	ph->phils = atoi_ph(av[1]);
	if (!ph->phils || ph->phils > 200)
		return (err_phils());
	ph->die_t = atoi_ph(av[2]);
	ph->eat_t = atoi_ph(av[3]);
	ph->slp_t = atoi_ph(av[4]);
	ph->meals = -1;
	if (av[5])
		ph->meals = atoi_ph(av[5]);
	if (!ph->die_t || !ph->eat_t || !ph->slp_t)
		return (err_range());
	return (SUCCESS);
}
