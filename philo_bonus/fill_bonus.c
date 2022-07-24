/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:19:16 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/19 20:14:18 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(void)
{
	printf ("Error\n");
	return (1);
}

int	check_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_isnumber(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	fill_it(int ac, char **av, t_f *f)
{
	if ((ac != 5 && ac != 6) || check_arg(av))
		exit (print_error());
	f->time = get_timeofday();
	f->nb_phl = ft_atoi (av[1]);
	f->tm_die = ft_atoi (av[2]);
	f->tm_eat = ft_atoi (av[3]);
	f->tm_slp = ft_atoi (av[4]);
	if (ac == 6)
	{
		f->nb_eat = ft_atoi(av[5]);
		if (f->nb_eat <= 0)
			return (print_error());
	}
	else
		f->nb_eat = -1;
	if (f->nb_phl <= 0 || f->nb_phl > 200 || f->tm_slp <= 0
		|| f->tm_die <= 0 || f->tm_eat <= 0)
		return (print_error());
	f->all_eat = 0;
	return (0);
}
