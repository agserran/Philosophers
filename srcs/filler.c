/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:49:58 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 14:49:58 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	filler(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->c[i].id = i + 1;
		data->c[i].lfork = i;
		data->c[i].rfork = (i + 1) % data->num_philos;
		data->c[i].d = data;
		data->c[i].times_eaten = 0;
		i++;
	}
}

int	initializer(t_data *data, char **argv)
{
	if (!parser(argv))
		return (1);
	data->num_philos = ft_atoi(argv[1]);
	data->t2d = ft_atoi(argv[2]);
	data->t2e = ft_atoi(argv[3]);
	data->t2s = ft_atoi(argv[4]);
	data->status = 0;
	data->all_eaten = 0;
	if (data->num_philos < 1 || data->t2d < 0 || data->t2e < 0
		|| data->t2s < 0 || data->num_philos > 250)
		return (1);
	if (argv[5])
	{
		data->max_dinner = ft_atoi(argv[5]);
		if (data->max_dinner <= 0)
			return (1);
	}
	else
		data->max_dinner = -1;
	if (create_forks(data))
		return (2);
	filler(data);
	return (0);
}

int	parser(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
