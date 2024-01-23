/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:49:51 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 14:49:51 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	life_checker(t_data *d)
{
	int	i;
	int	done;

	while (!(d->all_eaten) && !get_status(d))
	{
		i = -1;
		done = 0;
		while (++i < d->num_philos && !get_status(d))
		{
			if (time_diff(get_last(&d->c[i]), times()) > d->t2d)
			{
				set_status(d, 1);
				dead_printer(d, i + 1, "died");
				break ;
			}
			if (d->max_dinner > 0)
				if (get_times(&d->c[i]) >= d->max_dinner)
					done++;
		}
		if (done >= d->num_philos)
		{
			set_status(d, 1);
			break ;
		}
	}
}
