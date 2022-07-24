/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:49:08 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/24 16:34:23 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_f		f;
	t_philo	*philo;
	int		i;
	int		n;

	if (fill_it(ac, av, &f))
		return (1);
	n = ft_atoi(av[1]);
	f.fork = malloc((n + 1) * sizeof(pthread_mutex_t));
	philo = malloc((n + 1) * sizeof(t_philo));
	if (init_phil(&f, philo) || init_init (&f))
		return (1);
	if (philo_thread(&f, philo))
		return (1);
	observ (&f, philo);
	i = 1;
	while (i <= f.nb_phl)
	{
		pthread_mutex_destroy (&f.fork[i]);
		i++;
	}
	pthread_mutex_destroy (&f.philos);
	free(philo);
	free(f.fork);
	return (0);
}
