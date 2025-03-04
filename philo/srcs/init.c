#include "../incl/philo.h"

int	init(t_table *table)
{
	table->philos_full = 0;
	table->start = 0;
	table->stop = 0;
	table->philos = malloc(table->num_philos * sizeof(t_ph));
}