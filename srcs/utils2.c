/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:16 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 15:02:46 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_status(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->status_m);
	i = data->status;
	pthread_mutex_unlock(&data->status_m);
	return (i);
}

void	set_status(t_data *data, int val)
{
	pthread_mutex_lock(&data->status_m);
	data->status = val;
	pthread_mutex_unlock(&data->status_m);
}

long long	get_last(t_things *philo)
{
	long long	i;

	pthread_mutex_lock(&(philo->meal_m));
	i = philo->last_meal;
	pthread_mutex_unlock(&(philo->meal_m));
	return (i);
}

void	set_last(t_things *philo)
{
	pthread_mutex_lock(&(philo->meal_m));
	philo->last_meal = times();
	pthread_mutex_unlock(&(philo->meal_m));
}
