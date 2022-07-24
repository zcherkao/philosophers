/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:32:16 by zcherkao          #+#    #+#             */
/*   Updated: 2022/04/06 23:38:18 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_f *f, t_philo *philo)
{
	if (philo->last_eat + (size_t)f->tm_die <= get_timeofday())
	{
		print_status (f, philo->id_philo, "died");
		pthread_mutex_lock (&f->philos);
		return (1);
	}
	return (0);
}

void	observ(t_f *f, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == f->nb_phl)
			i = 0;
		if (check_dead(f, &philo[i + 1]))
			break ;
		if (f->all_eat == f->nb_phl)
		{
			pthread_mutex_lock (&f->philos);
			break ;
		}
		i++;
	}
}
