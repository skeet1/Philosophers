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

	tmp = (t_philo*)philo;
	if (tmp->index % 2)
		usleep(600);
	while (1)
	{
		pthread_mutex_lock(&tmp->data->fork[tmp->right_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "has taken a fork");
		pthread_mutex_lock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "has taken a fork");
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is eating");
		tmp->last_meal = ft_gettime();
		ft_usleep(tmp->data->time_eat);
		tmp[tmp->index].n_eating++;
		pthread_mutex_unlock(&tmp->data->fork[tmp->right_fork]);
		pthread_mutex_unlock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is sleeping");
		ft_usleep(tmp->data->time_sleep);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is thinking");
	}
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
			philo[i].right_fork = (i + 1) % data.num_philo;
			philo[i].left_fork = i;
			philo[i].n_eating = 0;
			philo[i].last_meal = 0;
			philo[i].data = &data;
		}
		i = 0;
		data.first_time = ft_gettime();
		while (i < data.num_philo)
		{
			philo[i].last_meal = ft_gettime();
			pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
			pthread_detach(philo[i].thread);
			i++;
		}
		// ft_death()
		// {
		usleep(500);
			while(!data.death)
			{
				i = -1;
				while(++i < data.num_philo)
				{
					if (ft_gettime() - philo[i].last_meal >= data.time_die)
					{
						ft_printf(philo[i].data, ft_gettime() - data.first_time, i + 1, "died");
						data.death = 1;
						return (0);
					}
				}
			}
	}
}
