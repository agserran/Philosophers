/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:20 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 16:49:11 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_things
{
	int						id;
	int						lfork;
	int						rfork;
	long long				last_meal;
	pthread_t				thread;
	struct s_data			*d;
	int						times_eaten;
	pthread_mutex_t			meal_m;
	pthread_mutex_t			times_m;
}	t_things;

typedef struct s_data
{
	int				num_philos;
	int				t2d;
	int				t2s;
	int				t2e;
	int				status;
	int				max_dinner;
	int				all_eaten;
	pthread_mutex_t	meal_checker;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	printer;
	pthread_mutex_t	status_m;
	t_things		c[250];
	long long		firts_time;
}	t_data;

int			arg_counter(int argc);
int			arg_parser(char **argv);
int			ft_atoi(const char *str);
int			ft_strlen(char *s);
long long	times(void);
long long	time_diff(long long now, long long past);
void		philo_printer(t_data *data, int id, char *s);
void		filler(t_data *data);
int			create_philos(t_data *data);
void		*life_routine(void *arg);
int			create_forks(t_data *data);
void		mutex_destroyer(t_data *d);
void		siesta(long long time, t_data *data);
void		fork_unlocker(t_things *c, t_data *d);
int			fork_locker(t_things *c, t_data *d);
int			dinner(t_things *c);
int			initializer(t_data *data, char **argv);
void		life_checker(t_data *d);
void		finisher(t_data *d, t_things *c);
void		set_status(t_data *data, int val);
int			get_status(t_data *data);
void		set_last(t_things *philo);
long long	get_last(t_things *philo);
int			get_times(t_things *philo);
void		set_times(t_things *philo);
void		dead_printer(t_data *c, int id, char *s);
int			parser(char **argv);

#endif
