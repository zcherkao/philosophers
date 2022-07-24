/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:38:46 by zcherkao          #+#    #+#             */
/*   Updated: 2022/04/06 23:24:25 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_phil(t_f *f, t_philo *philo)
{
	int	i;

	f->time = get_timeofday ();
	i = 1;
	while (i <= f->nb_phl)
	{
		philo[i].id_philo = i;
		philo[i].fork = i;
		if (i == f->nb_phl)
			philo[i].next_fork = 1;
		else
			philo[i].next_fork = i + 1;
		philo[i].number_of_eat = 0;
		philo[i].f = f;
		philo[i].last_eat = f->time;
		i++;
	}
	return (0);
}

int	init_init(t_f *f)
{
	int	i;

	if (pthread_mutex_init(&(f->philos), NULL))
	{
		printf ("Error\n");
		return (1);
	}
	i = 1;
	while (i <= f->nb_phl)
	{
		if (pthread_mutex_init (&(f->fork[i]), NULL))
		{
			printf ("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
