/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/06 07:52:35 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo			*tmp;
	int				id;
	// int				start;

	tmp = (t_philo*)philo;
	id = tmp->index;
	if (id % 2)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&tmp[id].data->fork);
		ft_printf("")
	}
	// printf("Hi i'm a philo number %d\n", id);
	// start = gettimeofday();
	// while (1)
	// {
	// 	pthread_mutex_lock(&tmp[id].mutex);
	// 	pthread_mutex_lock(&tmp[id - 1].mutex);
	// 	printf("%d %d has taken a right fork\n", gettimeofday(0, 0) - start, id);
	// 	printf("%d %d has taken a left fork\n", gettimeofday(0, 0) - start, id);
	// 	printf("%d %d is eating\n", gettimeofday(0, 0) - start, id);
	// 	pthread_mutex_unlock(&tmp[id].mutex);
	// 	pthread_mutex_unlock(&tmp[id-1].mutex);
	// }
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		data.num_philo = ft_atoi(argv[1]);
		data.time_die = ft_atoi(argv[2]);
		data.time_eat = ft_atoi(argv[3]);
		data.time_sleep = ft_atoi(argv[4]);
		data.death = 0;
		if (argc == 6)
			data.ntm_eat = ft_atoi(argv[5]);
		if (!ft_check_arg(data, argc) || !ft_check_num(argv, argc))
			return (0);
		philo = malloc(sizeof(t_philo) * data.num_philo);
		i = -1;
		data.fork = malloc(sizeof(pthread_mutex_t) * data.num_philo);
		while (++i < data.num_philo)
			pthread_mutex_init(&data.fork[i], NULL);
		pthread_mutex_init(&data.write, NULL);
		i = -1;
		while (++i < data.num_philo)
		{
			philo[i].index = (i + 1);
			philo[i].left_fork = (i + 1) % data.num_philo;
			philo[i].right_fork = i;
			philo[i].n_eating = 0;
			philo[i].last_mile = 0;
			philo[i].data = &data;
		}
		i = 0;
		data.first_time = ft_gettime();
		while (i < data.num_philo)
		{
			pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
			pthread_detach(philo[i].thread);
			i++;
			philo[i].last_eat = ft_gettime();
		}
		ft_death()
		{

			while(!data.death)
			{
				i = -1;
				while(philo[++i])
				{
					if ()
				}
			}

		}
		for (int i = 0 ; i < data.num_philo; i++)
		{
			pthread_join(philo[i].thread, NULL);
		}
	}
}
