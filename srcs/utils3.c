/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:02:08 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 15:02:39 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	siesta(long long time, t_data *data)
{
	long long	end;

	end = times() + time;
	while (!get_status(data))
	{
		if (times() >= end)
			break ;
		usleep(700);
	}
}

void	dead_printer(t_data *c, int id, char *s)
{
	pthread_mutex_lock(&(c->printer));
	printf("%lli ", times() - c->firts_time);
	printf("Philosopher %d ", id);
	printf("%s\n", s);
	pthread_mutex_unlock(&(c->printer));
}

int	get_times(t_things *philo)
{
	int	i;

	pthread_mutex_lock(&(philo->times_m));
	i = philo->times_eaten;
	pthread_mutex_unlock(&(philo->times_m));
	return (i);
}

void	set_times(t_things *philo)
{
	pthread_mutex_lock(&(philo->times_m));
	philo->times_eaten += 1;
	pthread_mutex_unlock(&(philo->times_m));
}
