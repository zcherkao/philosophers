/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:46:52 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/19 15:35:10 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct f
{
	int				nb_phl;
	int				tm_die;
	int				tm_eat;
	int				tm_slp;
	int				nb_eat;
	int				all_eat;
	long			time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	philos;
}	t_f;

typedef struct philo
{
	int			id_philo;
	int			fork;
	int			next_fork;
	int			number_of_eat;
	t_f			*f;
	size_t		last_eat;
	pthread_t	thread;
}	t_philo;

int		ft_isnumber(char *str);
int		ft_atoi(const char *str);
int		print_error(void);
int		ft_isnumber(char *str);
int		check_arg(char **av);
int		fill_it(int ac, char **av, t_f *f);
int		check_dead(t_f *f, t_philo *philo);
size_t	get_timeofday(void);
void	print_status(t_f *f, int id, char *msg);
int		init_phil(t_f *f, t_philo *philo);
void	observ(t_f *f, t_philo *philo);
int		philo_thread(t_f *f, t_philo *philo);
int		init_init(t_f *f);

#endif
