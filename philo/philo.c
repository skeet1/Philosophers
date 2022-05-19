/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/19 18:12:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*myHello(void *arg)
{
	sleep(1);
	(void)arg;
	printf("HELLO thou");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	pthread_t	*thread;
	int			i;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		philo.num_philo = ft_atoi(argv[1]);
		philo.time_die = ft_atoi(argv[2]);
		philo.time_eat = ft_atoi(argv[3]);
		philo.time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo.nt_eat = ft_atoi(argv[5]);
		thread = malloc(sizeof(pthread_t) * philo.num_philo);
		while (++i < philo.num_philo)
		{
			pthread_create(&thread[i], NULL, myHello, NULL);
			printf("we create thread number : %d\n", i);
		}

	}
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("%ld , %d", current_time.tv_sec, current_time.tv_usec);
}
