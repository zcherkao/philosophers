/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:00:00 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/20 14:30:18 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sleep(long s_time, t_philo *philo)
{
	long	sleep_start;
	long	current_time;

	sleep_start = get_timeofday();
	current_time = sleep_start;
	while (sleep_start + s_time > current_time)
	{
		if ((unsigned long)philo->f->tm_die < (current_time - philo->f->time
				- philo->last_eat))
		{
			sem_wait(philo->f->death);
			print_status (philo, philo->id_philo, "died");
			sem_close(philo->f->philos);
			sem_close(philo->f->forks);
			sem_close(philo->f->death);
			sem_unlink("forks_s");
			sem_unlink("print_s");
			sem_unlink("death_s");
			exit(EXIT_FAILURE);
		}
		current_time = get_timeofday();
	}
	return (0);
}
