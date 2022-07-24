/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:58:34 by zcherkao          #+#    #+#             */
/*   Updated: 2022/07/20 14:33:03 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include	<stdbool.h>
# include	<semaphore.h>
# include	<stdio.h>
# include	<signal.h>
# include	<fcntl.h>
# include	<sys/time.h>
# include	<sys/stat.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<string.h>
# include   <stdlib.h>
# include   <unistd.h>
# include   <sys/time.h>
# include   <pthread.h>

typedef struct philo
{
	int				id_philo;
	int				fork;
	int				number_of_eat;
	struct philo	*next;
	struct f		*f;
	pid_t			philo_p;
	size_t			last_eat;

}	t_philo;

typedef struct f
{
	int				nb_phl;
	int				tm_die;
	int				tm_eat;
	int				tm_slp;
	int				nb_eat;
	int				all_eat;
	long			time;
	pid_t			philo_p;
	pthread_t		*thrd;
	t_philo			*_first;
	t_philo			*philo;
	t_philo			*head;
	sem_t			*forks;
	sem_t			*philos;
	sem_t			*death;
	long			start_time;
}	t_f;

void		*init_creat(t_f *f);
int			ft_isnumber(char *str);
int			ft_atoi(const char *str);
int			print_error(void);
int			ft_isnumber(char *str);
int			check_arg(char **av);
int			fill_it(int ac, char **av, t_f *f);
int			check_dead(t_f *f, t_philo *philo);
long		get_timeofday(void);
void		print_status(t_philo *philo, int id, char *msg);
void		observ(t_f *f, t_philo *philo);
int			philo_thread(t_f *f, t_philo *philo);
int			init_init(t_f *f);
t_philo		*init_phil(t_f *f, int i, t_philo *philo);
int			routine(t_philo *philo, int nb_eat);
int			ft_sleep(long s_time, t_philo *philo);
void		end(t_f *f);
void		kill_process(t_f *data);
int			slepp(int time);
void		*kill_1(t_f *f, t_philo *philo);

#endif