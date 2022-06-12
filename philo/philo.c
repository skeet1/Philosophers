/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/12 16:13:59 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo			*tmp;

	tmp = (t_philo *)philo;
	if (tmp->index % 2)
		usleep(600);
	while (tmp->data->death == 0)
	{
		pthread_mutex_lock(&tmp->data->fork[tmp->right_fork]);
		ft_printf(tmp->data, tmp->data->first_time, tmp->index, "fork");
		pthread_mutex_lock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, tmp->data->first_time, tmp->index, "fork");
		ft_printf(tmp->data, tmp->data->first_time, tmp->index, "is eating");
		ft_usleep(tmp->data->time_eat, tmp->data);
		tmp->last_meal = ft_gettime();
		tmp->n_eating++;
		pthread_mutex_unlock(&tmp->data->fork[tmp->right_fork]);
		pthread_mutex_unlock(&tmp->data->fork[tmp->left_fork]);
		ft_printf(tmp->data, tmp->data->first_time, tmp->index, "is sleeping");
		ft_usleep(tmp->data->time_sleep, tmp->data);
		ft_printf(tmp->data, tmp->data->first_time, tmp->index, "is thinking");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	int		i;

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
		ft_init_philo(&philo, &data);
		ft_create_philo(&philo, &data);
		usleep(500);
		if (check_death(&data, philo, argc))
			return (0);
	}
	else
		printf("\033[0;31m\033[1mWE NEED AT LEAST 4 ARGUMNETS\033[0m\n");
}
