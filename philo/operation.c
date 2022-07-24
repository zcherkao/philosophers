/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:13:51 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/19 15:34:28 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	slepp(int time)
{
	size_t	t;

	t = get_timeofday() + time;
	while (get_timeofday() < t)
	{
		usleep (60);
	}
	return (0);
}

void	philo_eat(t_f *f, t_philo *philo)
{
	pthread_mutex_lock (&f->fork[philo->fork]);
	print_status (f, philo->id_philo, "has taken a fork");
	pthread_mutex_lock (&f->fork[philo->next_fork]);
	print_status (f, philo->id_philo, "has taken a fork");
	print_status (f, philo->id_philo, "is eating");
	philo->number_of_eat++;
	philo->last_eat = get_timeofday();
	if (philo->number_of_eat == f->nb_eat)
		f->all_eat++;
	slepp (f->tm_eat);
	pthread_mutex_unlock (&f->fork[philo->fork]);
	pthread_mutex_unlock (&f->fork[philo->next_fork]);
}

void	*routine(void *arg)
{
	t_f		*f;
	t_philo	*philo;

	philo = (t_philo *)arg;
	f = philo->f;
	if (philo->id_philo % 2 == 0)
		usleep (100);
	while (1)
	{
		philo_eat (f, philo);
		print_status (f, philo->id_philo, "is sleeping");
		slepp (f->tm_slp);
		print_status (f, philo->id_philo, "is thinking");
		if (philo->number_of_eat == f->nb_eat)
			break ;
	}
	return (NULL);
}

int	philo_thread(t_f *f, t_philo *philo)
{
	int	i;

	i = 1;
	while (i <= f->nb_phl)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, (&philo[i])))
		{
			printf ("Error\n");
			return (1);
		}
		if (pthread_detach(philo[i].thread))
		{
			printf ("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
