/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:13:35 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/13 11:20:39 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_init_philo(t_philo **ph, t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = *ph;
	i = -1;
	while (++i < data->num_philo)
	{
		philo[i].index = (i + 1);
		philo[i].right_fork = (i + 1) % data->num_philo;
		philo[i].left_fork = i;
		philo[i].n_eating = 0;
		philo[i].last_meal = 0;
		philo[i].data = data;
	}
}

void	ft_create_philo(t_philo **ph, t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = *ph;
	i = 0;
	data->first_time = ft_gettime();
	while (i < data->num_philo)
	{
		philo[i].last_meal = ft_gettime();
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		pthread_detach(philo[i].thread);
		i++;
	}
}

int	check_death(t_data *data, t_philo *philo, int argc)
{
	int		i;

	while (!data->death)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			if (ft_gettime() - philo[i].last_meal >= data->time_die)
			{
				pthread_mutex_lock(&data->write);
				printf("\033[0;36m %lld \033[0;34m%d \033[0;32m died\n",
					ft_gettime() - data->first_time, i + 1);
				data->death = 1;
				return (1);
			}
			if (ft_num_eating_check(philo, data->ntm_eat,
					data->num_philo, argc))
			{
				data->death = 1;
				usleep(100);
				return (1);
			}
		}
	}
	return (0);
}
