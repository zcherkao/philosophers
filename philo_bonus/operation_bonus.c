/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:01:04 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/24 13:56:50 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo, int nb_eat)
{
	sem_wait (philo->f->forks);
	print_status (philo, philo->id_philo, "has taken a fork");
	sem_wait (philo->f->forks);
	print_status (philo, philo->id_philo, "has taken a fork");
	print_status (philo, philo->id_philo, "is eating");
	ft_sleep (philo->f->tm_eat, philo);
	if (philo->number_of_eat == nb_eat)
		exit(0);
	philo->number_of_eat += 1;
	philo->last_eat = get_timeofday() - philo->f->time;
	sem_post(philo->f->forks);
	sem_post(philo->f->forks);
}

void	thinking(t_philo *philo)
{
	t_f	*f;

	f = NULL;
	print_status (philo, philo->id_philo, "is thinking");
	if (philo->number_of_eat == 0)
		ft_sleep(100, philo);
}

void	sleeping(t_philo *philo)
{
	t_f	*f;

	f = NULL;
	print_status (philo, philo->id_philo, "is sleeping");
	ft_sleep (philo->f->tm_slp, philo);
}

int	routine(t_philo *philo, int nb_eat)
{
	t_f		*f;

	f = NULL;
	if (philo->f->nb_phl == 1)
	{
		print_status (philo, philo->id_philo, "has taken a fork");
		ft_sleep(philo->f->tm_die, philo);
		print_status (philo, philo->id_philo, "died");
		exit (1);
	}
	while (1)
	{
		philo_eat (philo, nb_eat);
		if (philo->number_of_eat == philo->f->nb_eat)
			exit(1);
		sleeping (philo);
		thinking (philo);
	}
	return (0);
}
