/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/04 08:31:23 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo			*tmp;
	int				id;
	int				start;

	tmp = (t_philo*)philo;
	id = tmp->index;
	start = gettimeofday(0, 0);
	if (id % 2)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&tmp[id].mutex);
		pthread_mutex_lock(&tmp[id - 1].mutex);
		printf("%d %d has taken a right fork\n", gettimeofday(0, 0) - start, id);
		printf("%d %d has taken a left fork\n", gettimeofday(0, 0) - start, id);
		printf("%d %d is eating\n", gettimeofday(0, 0) - start, id);
		// printf("%d\n", tmp->);
		// usleep(100);
		pthread_mutex_unlock(&tmp[id].mutex);
		pthread_mutex_unlock(&tmp[id-1].mutex);
	}
}

void	ft_init_philo(t_philo *philo)
{
	static int	i;

	philo->index = ++i;
	philo->left_fork = 1;
	philo->right_fork = 1;
	philo->n_eating = 0;
	pthread_mutex_init(&philo->mutex, NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = -1;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc == 5 || argc == 6)
	{
		if (!ft_check_num(argv, argc))
			return (0);
		data->num_philo = ft_atoi(argv[1]);
		data->time_die = ft_atoi(argv[2]);
		data->time_eat = ft_atoi(argv[3]);
		data->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->ntm_eat = ft_atoi(argv[5]);
		ft_check_arg(data, argc);
		philo = malloc(sizeof(t_philo) * data->num_philo);
		i = -1;
		while (++i < data->num_philo)
		{
			// ft_init_philo(&philo[i]);
			philo[i].index = (i + 1);
			philo[i].left_fork = 1;
			philo[i].right_fork = 1;
			philo[i].n_eating = 0;
			philo[i].last_mile = 0;
			pthread_mutex_init(&philo[i].mutex, NULL);
		}
		i = 0;
		philo->data = data;
		while (i < data->num_philo)
		{
			pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
			pthread_detach(philo[i].thread);
			i++;
		}
		for (int i = 0 ; i < data->num_philo; i++)
		{
			pthread_join(philo[i].thread, NULL);
		}
		for (int i = 0; i < data->num_philo; i++)
			printf("index is %d ---- \n", philo[i].index);
	}
}
