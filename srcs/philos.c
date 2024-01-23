/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:07 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 16:40:21 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_data *data)
{
	int			i;
	t_things	*c;

	c = data->c;
	i = 0;
	data->firts_time = times();
	pthread_mutex_lock(&data->status_m);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&(c[i].meal_m), NULL))
			return (1);
		if (pthread_mutex_init(&(c[i].times_m), NULL))
			return (1);
		if (pthread_create(&c[i].thread, NULL, life_routine, &c[i]))
			return (1);
		set_last(&c[i]);
		i++;
	}
	pthread_mutex_unlock(&data->status_m);
	life_checker(data);
	finisher(data, c);
	return (0);
}

void	*life_routine(void *arg)
{
	t_things	*c;
	t_data		*data;

	c = (t_things *)arg;
	data = c->d;
	pthread_mutex_lock(&data->status_m);
	pthread_mutex_unlock(&data->status_m);
	if (c->id % 2 == 0)
		siesta(50, data);
	while (!get_status(data))
	{
		if (!dinner(c))
			break ;
		if (data->all_eaten)
			break ;
		philo_printer(data, c->id, "is sleeping");
		siesta(data->t2s, data);
		philo_printer(data, c->id, "is thinking");
		siesta(1, data);
	}
	return (NULL);
}

void	finisher(t_data *d, t_things *c)
{
	int	i;

	i = 0;
	while (i <= d->num_philos)
	{
		pthread_join(c[i].thread, NULL);
		i++;
	}
	mutex_destroyer(d);
}
