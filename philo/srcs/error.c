/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:00:41 by eelaine           #+#    #+#             */
/*   Updated: 2025/02/28 00:21:00 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	err_usage()
{
	printf("Please launch ./philo ");
	printf("with the following arguments:\n\n");
	printf("1. the number of philosophers\n");
	printf("2. the time when a philosopher should die\n");
	printf("3. the time it takes for a philosopher to eat\n");
	printf("4. the time a philosopher will spend sleeping\n\n");
	printf("optional:\n");
	printf("5. the number of times each philosopher eats\n\n");
	printf("valid arguments:\n");
	printf("- the number of philosophers 1 - 200\n");
	printf("- the duration of any action > 1\n");
	printf("- the number of meals can be >= 0\n");
	return (FAIL);
}

int	err_phils()
{
	printf("The number of philosophers can range from 1 to 200\n");
	return (FAIL);
}

int	err_range()
{
	printf("For the arguments defining the duration of an action please use values ranging from 1 to 2147483647\n");
	return (ERROR);
}
