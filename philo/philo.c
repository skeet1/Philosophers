/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:23 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/22 11:07:46 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alter(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2)
		printf("philo index : %d --- start eating\n", philo->index);
	return (NULL);
}

void	ft_init_philo(t_philo **philo)
{
	static int	i;
	t_philo		*ph;

	ph = *philo;
	ph->index = ++i;
	ph->left_fork = 1;
	ph->right_fork = 1;
	ph->n_eating = 1;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	**philo;
	int		i;

	i = -1;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc == 5 || argc == 6)
	{
		data->num_philo = ft_atoi(argv[1]);
		data->time_die = ft_atoi(argv[2]);
		data->time_eat = ft_atoi(argv[3]);
		data->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->ntm_eat = ft_atoi(argv[5]);
		ft_check_arg(data, argc);
		philo = malloc(sizeof(t_philo *) * data->num_philo);
		while (++i < data->num_philo)
		{
			philo[i] = malloc(sizeof(t_philo));
			ft_init_philo(&philo[i]);
		}
		for (int i = 0; i < data->num_philo; i++)
			printf("index is %d ---- \n", philo[i]->index);
	}
}
