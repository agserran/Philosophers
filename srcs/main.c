/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <agserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:01 by agserran          #+#    #+#             */
/*   Updated: 2023/09/28 14:50:01 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("WRONG AMOUNT OF ARGMUENTS.\n");
		return (1);
	}
	if (initializer(&data, argv))
	{
		printf("NON VALID ARGUMENTS.\n");
		return (0);
	}
	if (create_philos(&data))
	{
		printf("MUTEX CREATION ERROR.\n");
		return (2);
	}
	return (0);
}
