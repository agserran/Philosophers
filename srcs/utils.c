/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:31:15 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 15:02:51 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	num;

	num = 0;
	sign = 0;
	a = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign++;
		a++;
	}
	while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
	{
		num = num * 10 + str[a] - 48;
		a++;
	}
	if (sign % 2 != 0)
		num = num * -1;
	return (num);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	times(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_diff(long long past, long long now)
{
	return (now - past);
}

void	philo_printer(t_data *c, int id, char *s)
{
	pthread_mutex_lock(&(c->printer));
	if (!get_status(c))
	{
		printf("%lli ", times() - c->firts_time);
		printf("Philosopher %d ", id);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(c->printer));
}
