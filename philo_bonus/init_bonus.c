/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:16:16 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/20 14:26:58 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*init_phil(t_f *f, int i, t_philo *philo)
{
	i = 0;
	philo = malloc(sizeof(t_philo) * f->nb_phl);
	if (!philo)
		exit (1);
	while (i < f->nb_phl)
	{
		philo[i].f = f;
		philo[i].number_of_eat = 0;
		philo[i].id_philo = i + 1;
		philo[i].last_eat = 0;
		philo[i].philo_p = fork();
		if (philo[i].philo_p == -1)
			kill (philo[i].philo_p, SIGTERM);
		if (philo[i].philo_p == 0)
		{
			routine (philo + i, f->nb_eat);
		}
		i++;
	}
	kill_1(f, philo);
	return (philo);
}

void	*kill_1(t_f *f, t_philo *philo)
{
	int	i;
	int	j;

	while (waitpid (-1, &j, 0) > 0)
	{
		if (j == 256)
		{
			i = 0;
			while (i < f->nb_phl)
				kill (philo[i++].philo_p, SIGTERM);
		}
	}
	return (NULL);
}

void	*init_creat(t_f *f)
{
	t_philo	*philo;

	sem_unlink ("forks_s");
	sem_unlink ("death_s");
	sem_unlink ("print_s");
	f->thrd = malloc(sizeof(pthread_t) * f->nb_phl);
	f->forks = sem_open ("forks_s", O_CREAT, 0664, f->nb_phl);
	f->death = sem_open ("death_s", O_CREAT, 0664, 1);
	f->philos = sem_open ("print_s", O_CREAT, 0664, 1);
	philo = init_phil (f, 0, 0);
	free (philo);
	if (sem_close(f->philos) || sem_close(f->forks) || sem_close(f->death))
		exit (1);
	return (NULL);
}
