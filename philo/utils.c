/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:13:17 by mkarim            #+#    #+#             */
/*   Updated: 2022/06/06 07:52:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_check_num(char **argv, int argc)
{
	if (!ft_check(argv[1]) || !ft_check(argv[2]) || !ft_check(argv[3])
			|| !ft_check(argv[4]))
		return (ft_putstr("Error ARG\n"), 0);
	if (argc == 6)
		if (!ft_check(argv[5]))
			return (ft_putstr("Error ARG\n"), 0);
	return (1);
}

int	ft_check_arg(t_data data, int argc)
{
	if (data.num_philo < 1)
		return (ft_putstr("We need 2 philo at least\n"), 0);
	else if (argc == 6)
	{
		if (data.ntm_eat > 0)
			return(ft_putstr("each philospher must eat one time at least"), 0);
	}
	else if (data.time_die <= 60 || data.time_eat <= 60 || data.time_sleep <= 60)
		return (ft_putstr("Don't test with values lower than 60 :D\n"), 0);
	return (1);
}

long long	ft_atoi(char *s)
{
	long long	i;
	long long	res;
	long long	signe;

	i = 0;
	res = 0;
	signe = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - 48;
		i++;
	}
	return (res * signe);
}

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

long long	ft_gettime()
{
	struct timeval	val;

	gettimeofday(&val , NULL);
	return(val.tv_sec * 1000 + val.tv_usec / 1000);
}

void ft_printf(t_data *data, long long time, int id, char *info)
{
	if (data->death == 0)
	{
		pthread_mutex_lock(&data->write);
		printf("%lld %d %s\n", time, id, info);
		pthread_mutex_unlock(&data->write);
	}
}

void	ft_usleep(long long time)
{
	long long	enter_time;

	enter_time = ft_gettime();
	while (ft_gettime() - time < enter_time)
		usleep(100);
}

ft_num_eating_check(t_philo *philo, int n_eat)