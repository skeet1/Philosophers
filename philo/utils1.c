/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:39:56 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/12 14:56:21 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

long long	ft_gettime(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}

void	ft_printf(t_data *data, long long time, int id, char *info)
{
	if (data->death == 0)
	{
		pthread_mutex_lock(&data->write);
		printf("\033[0;36m %lld \033[0;34m%d \033[0;32m%s\n", time, id, info);
		pthread_mutex_unlock(&data->write);
	}
}

void	ft_usleep(long long time, t_data *data)
{
	long long	enter_time;

	enter_time = ft_gettime();
	while (ft_gettime() - time < enter_time && !(data->death))
		usleep(100);
}

int	ft_num_eating_check(t_philo *philo, int n_eat, int num_philo, int argc)
{
	int		i;

	i = 0;
	if (argc != 6)
		return (0);
	if (i < num_philo)
	{
		if (philo[i].n_eating < n_eat)
			return (0);
	}
	return (1);
}
