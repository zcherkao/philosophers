/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:55:25 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/24 13:55:41 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	b;
	int	res;
	int	i;

	i = 0;
	b = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * b);
}

void	print_status(t_philo *philo, int id, char *msg)
{
	sem_wait(philo->f->philos);
	printf ("%lu\t", get_timeofday() - philo->f->time);
	printf ("philo [%d] ", id);
	printf ("%s\n", msg);
	sem_post(philo->f->philos);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

long	get_timeofday(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
