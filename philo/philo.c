/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/12 15:01:26 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo			*tmp;

	tmp = (t_philo*)philo;
	if (tmp->index % 2)
		usleep(600);
	while (tmp->data->death == 0)
	{
		pthread_mutex_lock(&tmp->data->fork[tmp->right_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "has taken a fork");
		pthread_mutex_lock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "has taken a fork");
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is eating");
		tmp->last_meal = ft_gettime();
		ft_usleep(tmp->data->time_eat, tmp->data);
		if (tmp->data->death)
			return (NULL);
		tmp->n_eating++;
		pthread_mutex_unlock(&tmp->data->fork[tmp->right_fork]);
		pthread_mutex_unlock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is sleeping");
		ft_usleep(tmp->data->time_sleep, tmp->data);
		if (tmp->data->death)
			return (NULL);
		ft_printf(tmp->data, ft_gettime() - tmp->data->first_time, tmp->index, "is thinking");
	}
	return (NULL);
}

void	ft_init_data(t_data *data, int argc, char **argv)
{

	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->death = 0;
	if (argc == 6)
		data->ntm_eat = ft_atoi(argv[5]);
}

int	check_death(t_data *data, t_philo *philo, int argc)
{
	int		i;
	
	while(!data->death)
	{
		i = -1;
		while(++i < data->num_philo)
		{
			if (ft_gettime() - philo[i].last_meal >= data->time_die)
			{
				pthread_mutex_lock(&data->write);
				printf("\033[0;36m %lld \033[0;34m%d \033[0;32m died\n", ft_gettime() - data->first_time, i + 1);
				data->death = 1;
				return (1);
			}
			if (ft_num_eating_check(philo, data->ntm_eat, data->num_philo, argc))
			{
				data->death = 1;
				usleep(100);
				return (1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		ft_init_data(&data, argc, argv);
		if (!ft_check_num(argv, argc) || !ft_check_arg(data, argc))
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
			// pthread_detach(philo[i].thread);
			i++;
		}
		usleep(500);
		if (check_death(&data, philo, argc))
			return (0);
	}
	else
		printf("\033[0;31m\033[1mWE NEED AT LEAST 4 ARGUMNETS\033[0m\n");
}
