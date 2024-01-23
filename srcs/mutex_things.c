/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:04 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 14:57:24 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (33);
	}
	if (pthread_mutex_init(&(data->printer), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_checker), NULL))
		return (1);
	if (pthread_mutex_init(&(data->status_m), NULL))
		return (1);
	return (0);
}

void	mutex_destroyer(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->num_philos)
	{
		pthread_mutex_destroy(&d->c[i].meal_m);
		pthread_mutex_destroy(&d->c[i].times_m);
		pthread_mutex_destroy(&d->forks[i]);
	}
	pthread_mutex_destroy(&d->printer);
	pthread_mutex_destroy(&d->meal_checker);
	pthread_mutex_destroy(&d->status_m);
}
