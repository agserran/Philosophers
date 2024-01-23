/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:49:45 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 16:39:27 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dinner(t_things *c)
{
	t_data	*d;

	d = c->d;
	if (!fork_locker(c, d))
		return (0);
	philo_printer(d, c->id, "is eating");
	set_last(c);
	set_times(c);
	siesta(d->t2e, d);
	fork_unlocker(c, d);
	return (1);
}

int	fork_locker(t_things *c, t_data *d)
{
	pthread_mutex_lock(&d->forks[c->rfork]);
	philo_printer(d, c->id, "has taken his right fork");
	if (c->rfork == c->lfork)
		return (0);
	pthread_mutex_lock(&d->forks[c->lfork]);
	philo_printer(d, c->id, "has taken his left fork");
	return (1);
}

void	fork_unlocker(t_things *c, t_data *d)
{
	pthread_mutex_unlock(&d->forks[c->rfork]);
	pthread_mutex_unlock(&d->forks[c->lfork]);
}
