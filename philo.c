/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/14 09:03:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		philo.num_philo = ft_atoi(argv[1]);
		philo.time_die = ft_atoi(argv[2]);
		philo.time_eat = ft_atoi(argv[3]);
		philo.time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo.nt_eat = ft_atoi(argv[5]);
	}
}
