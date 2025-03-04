/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:00:41 by eelaine           #+#    #+#             */
/*   Updated: 2025/03/04 14:58:39 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	guide()
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
